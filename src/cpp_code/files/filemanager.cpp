#include "filemanager.h"

#include <QFileDialog>
#include <QStandardPaths>

#include <QDebug>

FileManager::FileManager(QObject *parent) : QObject{parent} {}

void FileManager::setLogAnalizer(
    std::shared_ptr<LogAnalizer> log_analizer_ptr) {

  logAnalizer = log_analizer_ptr;
}

void FileManager::openFile(const QUrl &path) {
  file = std::make_unique<QFile>(path.toLocalFile());
  logAnalizer->beginAnalize(std::move(file));
}
