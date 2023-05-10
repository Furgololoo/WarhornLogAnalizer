#ifndef GAMEPLAYLOGS_H
#define GAMEPLAYLOGS_H

#include <QJsonArray>
#include <QJsonObject>

#include "../logentry.h"

class GameplayLogs {
public:
  GameplayLogs();

  void addFatalErrorLog(LogEntry &&log) noexcept;
  void addErrorLog(LogEntry &&log) noexcept;
  void addWarningLog(LogEntry &&log) noexcept;
  void addInfoLog(LogEntry &&log) noexcept;

  void printStatus() const;

  QJsonArray getDescription() const;
  QJsonArray getLogsTitle(const LogType::ELogType type) const;

private:
  QJsonArray
  createLogsTitleArray(QMap<int, LogEntry> const *const logsMap) const;

  QMap<int, LogEntry> fatalErrorLogs;
  QMap<int, LogEntry> errorLogs;
  QMap<int, LogEntry> warningLogs;
  QMap<int, LogEntry> infoLogs;
};

#endif // GAMEPLAYLOGS_H
