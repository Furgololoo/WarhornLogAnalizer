#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QJsonArray>
#include <QObject>

#include "../ui_managers/descriptionwindowmanager.h"
#include "log_groups/gameplaylogs.h"

class LogManager : public QObject
{
    Q_OBJECT
public:
    explicit LogManager(QObject *parent = nullptr);

    void updateGameplayLog(std::unique_ptr<LogEntry> _log, const LogType ::ELogType type);

    void test();

public slots:
    QJsonArray getGameplayShortcut() const;
    QJsonArray getGameplayLogsTitle(const QString &type_str) const;

    void openDescription(const QString &type, quint16 index);
    void setDescWindowManager(DescriptionWindowManager *dwm);

private:
    GameplayLogs gameplayLogs;

    DescriptionWindowManager *descriptionWindowManager;
};

#endif // LOGMANAGER_H
