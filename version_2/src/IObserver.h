//
// Created by Александр Мангазеев on 24.04.2021.
//

#ifndef TSU_OLD_LAB_1_IOBSERVER_H
#define TSU_OLD_LAB_1_IOBSERVER_H

#include <QObject>

class IObserver: public QObject {
    Q_OBJECT
public:
    virtual QString getName() = 0;
    virtual qint64 getSize() = 0;
public slots:
    virtual void updateSize() = 0;
//    virtual void updateName(QString name) = 0;
};
#endif //TSU_OLD_LAB_1_IOBSERVER_H
