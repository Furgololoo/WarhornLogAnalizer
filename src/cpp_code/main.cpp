#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "objectmanager.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/qml/main.qml"_qs);

  ObjectManager objectManager;
  objectManager.setContextProperty(engine);
  objectManager.registerTypes();

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
