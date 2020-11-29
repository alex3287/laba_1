#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <QVector>
#include "file.h"

class Subject: public QObject
{
    Q_OBJECT
public:
    void attach(File *file);
    void detach(File *file);
signals:
    void size_change();
private:
    QVector <File*> list;
};

#endif // SUBJECT_H
