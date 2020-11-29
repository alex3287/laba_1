#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QObject>
#include <QString>

//Класс интерфейс, от которого будет наследоваться класс File


//наследуем от QObject чтобы можно было работать со slots и signal
class IObserver: public QObject
{
    Q_OBJECT
public slots: //слот отвечающий за обновления размера файла
    virtual void update_size(void) {};
    virtual int newFileSize(void) {};
};

#endif // IOBSERVER_H
