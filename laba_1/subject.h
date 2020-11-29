#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <QVector>
#include "file.h"

class Subject: public QObject
{
    Q_OBJECT

signals:
    void size_change();


};

#endif // SUBJECT_H
