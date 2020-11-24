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
public:
    File(QString name);
};

#endif // FILE_H
