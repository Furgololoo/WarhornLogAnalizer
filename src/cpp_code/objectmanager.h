#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <QObject>

#include <memory>

#include "files/filemanager.h"
#include "log/loganalizer.h"
#include "log/logmanager.h"

class QQmlApplicationEngine;

class ObjectManager : public QObject {
  Q_OBJECT
public:
  explicit ObjectManager(QObject *parent = nullptr);

  void setContextProperty(QQmlApplicationEngine &engine);
  void registerTypes();

signals:

private:
  std::shared_ptr<FileManager> fileManager;
  std::shared_ptr<LogAnalizer> logAnalizer;
  std::shared_ptr<LogManager> logManager;
};

#endif // OBJECTMANAGER_H
