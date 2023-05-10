#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <QColor>
#include <QJsonObject>

#include "logtype.h"

class LogEntry {
public:
  //  LogEntry(const LogEntry &) = default;
  explicit LogEntry(QJsonObject &obj, LogType::ELogType _type);

  void addData(QJsonObject &obj);

  QColor getColor() const;
  QString getTitle() const;
  LogType::ELogType getType() const;

private:
  void setColor();

  LogType::ELogType type;
  QJsonObject data;

  QColor color;
};

#endif // LOGENTRY_H
