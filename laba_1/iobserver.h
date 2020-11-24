#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QObject>
#include <QString>

class IObserver : QObject
{
    Q_OBJECT
public:
//    IObserver();
    virtual void update(QString name);
};

#endif // IOBSERVER_H
