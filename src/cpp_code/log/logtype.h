#pragma once

#include <QString>

namespace LogType {

enum ELogType {
  FileInfo,
  Metadata,
  MonitorInfo,
  GPUInfo,
  LogDevObjectVersion,
  Warhorn_FatalError,
  Warhorn_Error,
  Warhorn_Warning,
  Warhorn_Info,
  Unknown
};

QString warhornTypeToString(const QString &type);

QString toString(const ELogType type);

ELogType toELogType(const QString &type);

} // namespace LogType
