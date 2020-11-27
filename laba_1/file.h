#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include "iobserver.h"


class File :public IObserver
{
    Q_OBJECT
private:
    QString name;
    int fileSize;
public:
    File(QString name);
public slots:
    void update_size(int newFileSize);
};

#endif // FILE_H
