#include "logentry.h"

// LogEntry::LogEntry(QObject *parent) : QObject{parent} {}

using namespace LogType;

LogEntry::LogEntry(QJsonObject &obj, ELogType _type) {
  type = _type;
  data = obj;
}

void LogEntry::addData(QJsonObject &obj) {}

QColor LogEntry::getColor() const { return color; }

QString LogEntry::getTitle() const { return data["title"].toString(); }

ELogType LogEntry::getType() const {
  return LogType::toELogType(data["type"].toString());
}

void LogEntry::setColor() {
  switch (type) {
  case FileInfo:
    QColor("#000000");
    break;
  case Metadata:
    QColor("#2E93FF");
    break;
  case MonitorInfo:
    QColor("#000000");
    break;
  case GPUInfo:
    QColor("#F55100");
    break;
  case LogDevObjectVersion:
    QColor("#000000");
    break;
  case Warhorn_FatalError:
    QColor("#6D00E0");
    break;
  case Warhorn_Error:
    QColor("#F40038");
    break;
  case Warhorn_Warning:
    QColor("#EBB502");
    break;
  case Warhorn_Info:
    QColor("#35FF23");
    break;
  case Unknown:
    QColor("#000000");
    break;
  default:
    QColor("#000000");
    break;
  }
}
