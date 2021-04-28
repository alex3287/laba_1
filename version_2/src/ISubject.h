//
// Created by Александр Мангазеев on 24.04.2021.
//

#ifndef TSU_OLD_LAB_1_ISUBJECT_H
#define TSU_OLD_LAB_1_ISUBJECT_H

#include <QObject>
#include "IObserver.h"

class ISubject: public QObject{
    Q_OBJECT
public:
    virtual void addFile(IObserver *obj) = 0;
    virtual void removeFile(IObserver *obj) = 0;
    virtual void notify() = 0;
    virtual void showLists() = 0;

    // TODO реализация с помощью сигналов и слотов
    virtual void attach(IObserver *obj) = 0;
    virtual void detach(IObserver *obj) = 0;

    virtual ~ISubject() {};
signals:
    virtual void changeSize() = 0; // TODO возможно тут нужно для имени и размера писать отдельно
};
#endif //TSU_OLD_LAB_1_ISUBJECT_H
