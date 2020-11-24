#ifndef IOBSERVER_H
#define IOBSERVER_H

//#include <QObject>
#include <QString>

class IObserver
{
public:
    virtual void update(QString name);
};

#endif // IOBSERVER_H
