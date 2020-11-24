#ifndef SUBJECT_H
#define SUBJECT_H

#include <QVector>
#include "file.h"

class Subject
{
private:
    QVector<File*> list;
public:
    void attach(File *file);
    void detach(File *file);
    void notify_size(int file_size);
};

#endif // SUBJECT_H
