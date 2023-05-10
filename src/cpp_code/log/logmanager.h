#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QJsonArray>
#include <QObject>

#include "log_groups/gameplaylogs.h"
//#include "logentry.h"
//#include "logtype.h"

class LogManager : public QObject {
  Q_OBJECT
public:
  explicit LogManager(QObject *parent = nullptr);

  void updateGameplayLog(LogEntry &&_log, const LogType ::ELogType type);

  void test();

public slots:
  QJsonArray getGameplayShortcut() const;
  QJsonArray getGameplayLogsTitle(const QString &type_str) const;

private:
  GameplayLogs gameplayLogs;
};

#endif // LOGMANAGER_H
