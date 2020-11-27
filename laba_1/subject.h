#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include "file.h"

class Subject: public QObject
{
    Q_OBJECT
signals:
    void size_change(int newFileName);
};

#endif // SUBJECT_H
