#include "objectmanager.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ui_managers/descriptionwindowmanager.h"

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

void ObjectManager::registerTypes() {
  qmlRegisterType<DescriptionWindowManager>("Managers", 1, 0,
                                            "DescriptionWindowManager");
}
