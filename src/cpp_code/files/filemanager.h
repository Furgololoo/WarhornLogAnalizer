#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QObject>

#include "../log/loganalizer.h"

class FileManager : public QObject {
  Q_OBJECT
public:
  FileManager(QObject *parent = nullptr);

  void setLogAnalizer(std::shared_ptr<LogAnalizer> log_analizer_ptr);

public slots:
  void openFile(const QUrl &path);

private:
  std::unique_ptr<QFile> file;
  std::shared_ptr<LogAnalizer> logAnalizer;
};

#endif // FILEMANAGER_H
