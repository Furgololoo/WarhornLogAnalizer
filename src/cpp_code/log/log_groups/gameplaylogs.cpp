#include "gameplaylogs.h"

#include <QDebug>
#include <map>
#include <memory>

GameplayLogs::GameplayLogs()
{
    fatalErrorLogs = std::make_shared<std::map<int, std::unique_ptr<LogEntry>>>();
    errorLogs = std::make_shared<std::map<int, std::unique_ptr<LogEntry>>>();
    warningLogs = std::make_shared<std::map<int, std::unique_ptr<LogEntry>>>();
    infoLogs = std::make_shared<std::map<int, std::unique_ptr<LogEntry>>>();
}

void GameplayLogs::addFatalErrorLog(std::unique_ptr<LogEntry> log)
{
    Q_ASSERT(fatalErrorLogs);
    fatalErrorLogs->insert(std::make_pair(fatalErrorLogs->size(), std::move(log)));

#ifdef DEBUG_LOGS
    (*fatalErrorLogs)[0]->showStatus();
#endif
    qDebug() << "Map address: " << &fatalErrorLogs;
}

void GameplayLogs::addErrorLog(std::unique_ptr<LogEntry> log)
{
    Q_ASSERT(errorLogs);
    errorLogs->insert(std::make_pair(errorLogs->size(), std::move(log)));
}

void GameplayLogs::addWarningLog(std::unique_ptr<LogEntry> log)
{
    Q_ASSERT(warningLogs);
    warningLogs->insert(std::make_pair(warningLogs->size(), std::move(log)));
}

void GameplayLogs::addInfoLog(std::unique_ptr<LogEntry> log)
{
    Q_ASSERT(infoLogs);
    infoLogs->insert(std::make_pair(infoLogs->size(), std::move(log)));
}

void GameplayLogs::printStatus() const
{
    qDebug() << "=============   GameplayLog Status   =============";
    qDebug() << "\n";
    qDebug() << "FatalError size: " << fatalErrorLogs->size();
    qDebug() << "errorLogs size: " << errorLogs->size();
    qDebug() << "warningLogs size: " << warningLogs->size();
    qDebug() << "infoLogs size: " << infoLogs->size();
    qDebug() << "\n";
    qDebug() << "==================================================";
}

QJsonArray GameplayLogs::getShortcut() const
{
    QJsonArray shortcutArray;

    QJsonObject fatalErrorShortcut{
        {"title", "Fatal Errors"}, {"count", static_cast<int>(fatalErrorLogs->size())}, {"type", "Warhorn_FatalError"}};
    QJsonObject errorShortcut{
        {"title", "Errors"}, {"count", static_cast<int>(errorLogs->size())}, {"type", "Warhorn_Error"}};
    QJsonObject warningShortcut{
        {"title", "Warnings"}, {"count", static_cast<int>(warningLogs->size())}, {"type", "Warhorn_Warning"}};
    QJsonObject infoShortcut{
        {"title", "Info"}, {"count", static_cast<int>(infoLogs->size())}, {"type", "Warhorn_Info"}};

    shortcutArray.append(fatalErrorShortcut);
    shortcutArray.append(errorShortcut);
    shortcutArray.append(warningShortcut);
    shortcutArray.append(infoShortcut);

    return shortcutArray;
}

QJsonObject &GameplayLogs::getDescription(const QString &type, const int index) const
{
    auto map = std::move(getLogMapByType(type));
    QJsonObject description(map->at(index)->getDescription());

    return description;
}

QJsonArray GameplayLogs::getLogsTitle(const LogType::ELogType type) const
{
    QJsonArray logsTitle;
    switch (type)
    {
    case LogType::Warhorn_FatalError:
        logsTitle = createLogsTitleArray(fatalErrorLogs);
        break;
    case LogType::Warhorn_Error:
        logsTitle = createLogsTitleArray(errorLogs);
        break;
    case LogType::Warhorn_Warning:
        logsTitle = createLogsTitleArray(warningLogs);
        break;
    case LogType::Warhorn_Info:
        logsTitle = createLogsTitleArray(infoLogs);
        break;
    }

    return logsTitle;
}

QJsonArray GameplayLogs::createLogsTitleArray(std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> logsMap) const
{
    qDebug() << "Map size: " << logsMap->size();
    QJsonArray logsTitle;
    // qDebug() << "Map address: " << &fatalErrorLogs;
    qDebug() << "Map address: " << &logsMap;
    (*fatalErrorLogs)[0]->showStatus();

    for (auto const &log : *logsMap)
    {
        log.second->showStatus();
        QJsonObject obj{{"title", log.second->getTitle()}, {"type", LogType::toString(log.second->getType())}};
        logsTitle.append(obj);
    }
    return logsTitle;
}

std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> GameplayLogs::getLogMapByType(const QString &type) const
{
    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> logMapPtr;

    switch (LogType::toELogType(type))
    {
    case LogType::Warhorn_FatalError:
        logMapPtr = std::move(fatalErrorLogs);
        break;
    case LogType::Warhorn_Error:
        logMapPtr = std::move(errorLogs);
        break;
    case LogType::Warhorn_Warning:
        logMapPtr = std::move(warningLogs);
        break;
    case LogType::Warhorn_Info:
        logMapPtr = std::move(infoLogs);
        break;
    default:
        qWarning() << __FUNCTION__ << " Bad log type: " << type;
        break;
    }

    qDebug() << __FUNCTION__;
    qDebug() << "Map: " << &logMapPtr;


    return logMapPtr;
}
