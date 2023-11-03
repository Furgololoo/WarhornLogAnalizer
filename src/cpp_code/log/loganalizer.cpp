#include "loganalizer.h"

#include <QDebug>

#include "../helpers/scopedtimer.h"

LogAnalizer::LogAnalizer(QObject *parent) : QObject{parent} {}

void LogAnalizer::beginAnalize(std::unique_ptr<QFile> file_ptr)
{
    file = std::move(file_ptr);
    qDebug() << "LogAnalizer::beginAnalize";
    readLogs();
}

void LogAnalizer::setLogManager(std::shared_ptr<LogManager> logManager_ptr) { logManager = logManager_ptr; }

void LogAnalizer::readLogs()
{
    ScopedTimer timer(__FUNCTION__);

    qDebug() << "file: " << file->fileName();
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "!file->open(QIODevice::ReadOnly | QIODevice::Text)";
        return;
    }

    while (!file->atEnd())
    {
        QString line = file->readLine();
        groupData(line);
    }
    file->close();
    logManager->test();
    emit endRead();
}

void LogAnalizer::groupData(QString &line)
{

    if (line.contains("Log file open"))
        createMetadataLog(line);
    else if (line.contains("&^&"))
        createGameplayLog(line);
    else if (line.contains("Metadata"))
        createMetadataLog(line);
}

void LogAnalizer::createGameplayLog(QString &line)
{
    QJsonObject data;
    int separator = line.indexOf("&^&");
    separator += 3;
    line = line.remove(0, separator);

    auto separated_data = line.split("|");
    QString appType = LogType::warhornTypeToString(separated_data[1]);

    data.insert("type", appType);
    data.insert("title", separated_data[0]);
    data.insert("additionalData", separated_data[2]);

    LogType::ELogType logType = LogType::toELogType(appType);

    std::unique_ptr<LogEntry> log = std::make_unique<LogEntry>(data, logType);

    logManager->updateGameplayLog(std::move(log), logType);
}

void LogAnalizer::createMetadataLog(QString &line) {}
