#ifndef GAMEPLAYLOGS_H
#define GAMEPLAYLOGS_H

#include <QJsonArray>
#include <QJsonObject>
#include <QSharedPointer>

#include "../logentry.h"

class GameplayLogs
{
public:
    GameplayLogs();
    GameplayLogs(const GameplayLogs *) = delete;
    GameplayLogs &operator=(const GameplayLogs *) = delete;

    void addFatalErrorLog(std::unique_ptr<LogEntry> log);
    void addErrorLog(std::unique_ptr<LogEntry> log);
    void addWarningLog(std::unique_ptr<LogEntry> log);
    void addInfoLog(std::unique_ptr<LogEntry> log);

    void printStatus() const;

    QJsonArray getShortcut() const;
    QJsonArray getLogsTitle(const LogType::ELogType type) const;
    QJsonObject &getDescription(const QString &type, const int index) const;

private:
    QJsonArray createLogsTitleArray(std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>>) const;

    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> getLogMapByType(const QString &type) const;

    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> fatalErrorLogs;
    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> errorLogs;
    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> warningLogs;
    std::shared_ptr<std::map<int, std::unique_ptr<LogEntry>>> infoLogs;
};

#endif // GAMEPLAYLOGS_H
