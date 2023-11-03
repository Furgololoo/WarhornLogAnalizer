#ifndef DESCRIPTIONWINDOWMANAGER_H
#define DESCRIPTIONWINDOWMANAGER_H

#include <QJsonObject>
#include <QObject>
#include <QQuickItem>

class DescriptionWindowManager : public QQuickItem
{
    Q_OBJECT


public:
    DescriptionWindowManager();

    void setData(QJsonObject &data);

public slots:
    QString getTitle() const;
    QString getDescription() const;
    void clear();

signals:

    void display();

private:
    QJsonObject descriptionData;
};

#endif // DESCRIPTIONWINDOWMANAGER_H
