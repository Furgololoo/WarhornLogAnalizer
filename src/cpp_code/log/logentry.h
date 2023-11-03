#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <QColor>
#include <QJsonObject>

#include "logtype.h"

class LogEntry
{
public:
    LogEntry();
    explicit LogEntry(QJsonObject &obj, LogType::ELogType _type);
    LogEntry(const LogEntry &log) = delete;
    LogEntry &operator=(const LogEntry &log) = delete;

    void addData(QJsonObject &obj);

    QJsonObject getDescription() const;

    QColor getColor() const;
    QString getTitle() const;
    QJsonObject getData() const;
    LogType::ELogType getType() const;

#ifdef DEBUG_LOGS
    void showStatus() const;
#endif

private:
    void setColor();

    LogType::ELogType type;
    QJsonObject data;

    QColor color;
};

#endif // LOGENTRY_H
