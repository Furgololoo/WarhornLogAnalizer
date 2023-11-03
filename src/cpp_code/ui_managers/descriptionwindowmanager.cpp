#include "descriptionwindowmanager.h"

DescriptionWindowManager::DescriptionWindowManager() {}

void DescriptionWindowManager::setData(QJsonObject &data)
{
    descriptionData = data;
    emit display();
}

QString DescriptionWindowManager::getTitle() const { return descriptionData["title"].toString(); }

QString DescriptionWindowManager::getDescription() const { return descriptionData["data"].toString(); }

void DescriptionWindowManager::clear()
{

}
