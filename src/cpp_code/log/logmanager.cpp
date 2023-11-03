#include "logmanager.h"

LogManager::LogManager(QObject *parent) : QObject{parent} {}

void LogManager::updateGameplayLog(std::unique_ptr<LogEntry> _log, const LogType::ELogType type)
{
    switch (type)
    {
    case LogType::Warhorn_FatalError:
        gameplayLogs.addFatalErrorLog(std::move(_log));
        break;
    case LogType::Warhorn_Error:
        gameplayLogs.addErrorLog(std::move(_log));
        break;
    case LogType::Warhorn_Warning:
        gameplayLogs.addWarningLog(std::move(_log));
        break;
    case LogType::Warhorn_Info:
        gameplayLogs.addInfoLog(std::move(_log));
        break;
    default:
        Q_STATIC_ASSERT_X(true, "Passed bad LogType to GameplayLogs");
    }
}

void LogManager::test() { gameplayLogs.printStatus(); }

QJsonArray LogManager::getGameplayShortcut() const { return gameplayLogs.getShortcut(); }

QJsonArray LogManager::getGameplayLogsTitle(const QString &type_str) const
{
    return gameplayLogs.getLogsTitle(LogType::toELogType(type_str));
}

void LogManager::openDescription(const QString &type, quint16 index)
{
    descriptionWindowManager->setData(gameplayLogs.getDescription(type, index));
}

void LogManager::setDescWindowManager(DescriptionWindowManager *dwm) { descriptionWindowManager = dwm; }
