#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include "iobserver.h"


class File :public IObserver
{
    Q_OBJECT
public:
    File(QString name);
    int newFileSize(void);
    QString printFileName();
public slots:
    void update_size(void);
private:
    QString name;
    int fileSize;
};

#endif // FILE_H
