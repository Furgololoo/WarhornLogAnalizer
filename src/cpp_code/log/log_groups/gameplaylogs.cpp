#include "gameplaylogs.h"

#include <QDebug>

GameplayLogs::GameplayLogs() {}

void GameplayLogs::addFatalErrorLog(LogEntry &&log) noexcept {
  fatalErrorLogs.insert(fatalErrorLogs.size(), std::move(log));
}

void GameplayLogs::addErrorLog(LogEntry &&log) noexcept {
  errorLogs.insert(errorLogs.size(), std::move(log));
}

void GameplayLogs::addWarningLog(LogEntry &&log) noexcept {
  warningLogs.insert(warningLogs.size(), std::move(log));
}

void GameplayLogs::addInfoLog(LogEntry &&log) noexcept {
  infoLogs.insert(infoLogs.size(), std::move(log));
}

void GameplayLogs::printStatus() const {
  qDebug() << "=============   GameplayLog Status   =============";
  qDebug() << "\n";
  qDebug() << "FatalError size: " << fatalErrorLogs.size();
  qDebug() << "errorLogs size: " << errorLogs.size();
  qDebug() << "warningLogs size: " << warningLogs.size();
  qDebug() << "infoLogs size: " << infoLogs.size();
  qDebug() << "\n";
  qDebug() << "==================================================";
}

QJsonArray GameplayLogs::getDescription() const {
  QJsonArray shortcutArray;

  QJsonObject fatalErrorShortcut{{"title", "Fatal Errors"},
                                 {"count", fatalErrorLogs.count()},
                                 {"type", "Warhorn_FatalError"}};
  QJsonObject errorShortcut{{"title", "Errors"},
                            {"count", errorLogs.count()},
                            {"type", "Warhorn_Error"}};
  QJsonObject warningShortcut{{"title", "Warnings"},
                              {"count", warningLogs.count()},
                              {"type", "Warhorn_Warning"}};
  QJsonObject infoShortcut{
      {"title", "Info"}, {"count", infoLogs.count()}, {"type", "Warhorn_Info"}};

  shortcutArray.append(fatalErrorShortcut);
  shortcutArray.append(errorShortcut);
  shortcutArray.append(warningShortcut);
  shortcutArray.append(infoShortcut);

  return shortcutArray;
}

QJsonArray GameplayLogs::getLogsTitle(const LogType::ELogType type) const {
  QJsonArray logsTitle;

  switch (type) {
  case LogType::Warhorn_FatalError:
    logsTitle = createLogsTitleArray(&fatalErrorLogs);
    break;
  case LogType::Warhorn_Error:
    logsTitle = createLogsTitleArray(&errorLogs);
    break;
  case LogType::Warhorn_Warning:
    logsTitle = createLogsTitleArray(&warningLogs);
    break;
  case LogType::Warhorn_Info:
    logsTitle = createLogsTitleArray(&infoLogs);
    break;
  }

  return logsTitle;
}

QJsonArray GameplayLogs::createLogsTitleArray(
    const QMap<int, LogEntry> *const logsMap) const {
  QJsonArray logsTitle;
  for (auto log : *logsMap) {
    QJsonObject obj{{"title", log.getTitle()},
                    {"type", LogType::toString(log.getType())}};
    logsTitle.append(obj);
  }
  return logsTitle;
}
