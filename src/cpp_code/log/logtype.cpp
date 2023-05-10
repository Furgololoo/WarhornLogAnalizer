#include "logtype.h"

namespace LogType {

QString warhornTypeToString(const QString &type) {
  if (type == "W_FATAL_ERROR!!!")
    return "Warhorn_FatalError";

  else if (type == "W_ERROR!!")
    return "Warhorn_Error";

  else if (type == "W_WARNING!")
    return "Warhorn_Warning";

  else if (type == "W_INFO")
    return "Warhorn_Info";

  else
    return "Unknown";
}

QString toString(const ELogType type) {
  if (type == Warhorn_FatalError)
    return "Warhorn_FatalError";

  else if (type == Warhorn_Error)
    return "Warhorn_Error";

  else if (type == Warhorn_Warning)
    return "Warhorn_Warning";

  else if (type == Warhorn_Info)
    return "Warhorn_Info";

  else
    return "Unknown";
}

ELogType toELogType(const QString &type) {
  if (type == "Warhorn_FatalError")
    return Warhorn_FatalError;

  else if (type == "Warhorn_Error")
    return Warhorn_Error;

  else if (type == "Warhorn_Warning")
    return Warhorn_Warning;

  else if (type == "Warhorn_Info")
    return Warhorn_Info;

  else
    return Unknown;
}

} // namespace LogType
