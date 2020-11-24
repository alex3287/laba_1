#ifndef IOBSERVER_H
#define IOBSERVER_H

//#include <QObject>
#include <QString>

class IObserver
{
public:
    virtual void update_size(int file_size) = 0;
};

#endif // IOBSERVER_H
