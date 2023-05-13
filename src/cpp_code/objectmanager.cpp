#include "objectmanager.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

ObjectManager::ObjectManager(QObject *parent) : QObject{parent} {
  fileManager = std::make_shared<FileManager>();
  logAnalizer = std::make_shared<LogAnalizer>();
  logManager = std::make_shared<LogManager>();

  logAnalizer->setLogManager(logManager);
  fileManager->setLogAnalizer(logAnalizer);
}

void ObjectManager::setContextProperty(QQmlApplicationEngine &engine) {
  engine.rootContext()->setContextProperty("FileManager", fileManager.get());
  engine.rootContext()->setContextProperty("LogAnalizer", logAnalizer.get());
  engine.rootContext()->setContextProperty("LogManager", logManager.get());
}

void ObjectManager::registerTypes() {}
