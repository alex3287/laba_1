//
// Created by Александр Мангазеев on 25.04.2021.
//

#ifndef TSU_OLD_LAB_1_FILE_H
#define TSU_OLD_LAB_1_FILE_H

#include <QFileInfo>
#include "IObserver.h"
#include "ISubject.h"
#include "Publisher.h"

class File: public IObserver{
    Q_OBJECT
public:
    File(QString name, qint64 size);
    qint64 getSize() override;
    QString getName() override;
    qint64 newFileSize();
public slots:
    void updateSize();
private:
//    ISubject *publisher;
    QString name;
    qint64 size;
};


#endif //TSU_OLD_LAB_1_FILE_H
