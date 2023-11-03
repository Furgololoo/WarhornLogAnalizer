#ifndef LOGBASE_H
#define LOGBASE_H

#include <QJsonArray>
#include <QJsonObject>

//#include "../logentry.h"

class LogBase {
public:
  LogBase();

  void printStatus() const;

  virtual QJsonArray getDescription() const;
  virtual QJsonArray getLogsTitle(const LogType::ELogType type) const;

protected:
};

#endif // LOGBASE_H
