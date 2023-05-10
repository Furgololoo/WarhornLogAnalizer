#ifndef LOGANALIZER_H
#define LOGANALIZER_H

#include <QFile>
#include <QJsonObject>
#include <QMap>
#include <QObject>

//#include "logentry.h"
#include "logmanager.h"

class LogAnalizer : public QObject {
  Q_OBJECT
public:
  explicit LogAnalizer(QObject *parent = nullptr);

  void beginAnalize(std::unique_ptr<QFile> file_ptr);
  void setLogManager(std::shared_ptr<LogManager> logManager_ptr);

signals:

  void endRead();

private:
  void readLogs();
  void groupData(QString &line);

  void createGameplayLog(QString &line);
  void createMetadataLog(QString &line);

  std::unique_ptr<QFile> file;
  std::shared_ptr<LogManager> logManager;
};

#endif // LOGANALIZER_H
