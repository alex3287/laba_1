#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QObject>

//Класс интерфейс, от которого будет наследоваться класс File


//наследуем от QObject чтобы можно было работать со slots и signal
class IObserver: public QObject
{
    Q_OBJECT  //специальный макрос
public slots: //слот отвечающий за обновления размера файла
    virtual void update_size(int newFileSize) = 0;
};

#endif // IOBSERVER_H
