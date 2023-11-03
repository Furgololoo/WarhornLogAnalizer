#include "logentry.h"

using namespace LogType;

LogEntry::LogEntry() {}


LogEntry::LogEntry(QJsonObject &obj, ELogType _type)
{
    type = _type;
    data = obj;
}

void LogEntry::addData(QJsonObject &obj) {}

QJsonObject LogEntry::getDescription() const
{
    QJsonObject descriptionData;

    descriptionData.insert("title", getTitle());
    descriptionData.insert("type", toString(getType()));
    descriptionData.insert("data", getData());
    descriptionData.insert("color", getColor().name(QColor::HexRgb));

    return descriptionData;
}

QColor LogEntry::getColor() const { return color; }

QString LogEntry::getTitle() const
{
    qDebug() << data["title"].toString();
    return data["title"].toString();
}

QJsonObject LogEntry::getData() const { return data; }

ELogType LogEntry::getType() const { return LogType::toELogType(data["type"].toString()); }

#ifdef DEBUG_LOGS
void LogEntry::showStatus() const
{
    qDebug() << "Address: " << this;
    qDebug() << data["title"].toString();
}
#endif

void LogEntry::setColor()
{
    switch (type)
    {
    case FileInfo:
        color = QColor("#000000");
        break;
    case Metadata:
        color = QColor("#2E93FF");
        break;
    case MonitorInfo:
        color = QColor("#000000");
        break;
    case GPUInfo:
        color = QColor("#F55100");
        break;
    case LogDevObjectVersion:
        color = QColor("#000000");
        break;
    case Warhorn_FatalError:
        color = QColor("#6D00E0");
        break;
    case Warhorn_Error:
        color = QColor("#F40038");
        break;
    case Warhorn_Warning:
        color = QColor("#EBB502");
        break;
    case Warhorn_Info:
        color = QColor("#35FF23");
        break;
    case Unknown:
        color = QColor("#000000");
        break;
    default:
        color = QColor("#000000");
        break;
    }
}
