#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include "iobserver.h"

class File : QObject, public IObserver
{
    Q_OBJECT
private:
    QString name;
    int file_size;
public:
    File(QString name);
    void update_size(int file_size);
};

#endif // FILE_H
