//
// Created by Александр Мангазеев on 24.04.2021.
//

#ifndef TSU_OLD_LAB_1_PUBLISHER_H
#define TSU_OLD_LAB_1_PUBLISHER_H

#include <QVector>
#include <QString>
#include <QTextStream>
#include "ISubject.h"
#include "IObserver.h"
#include <vector>
#include "File.h"

class Publisher: public ISubject{
    Q_OBJECT
public:

    Publisher();

    void addFile(IObserver *obj) override;
    void removeFile(IObserver *obj) override;
    void showLists() override;
    void notify() override;

    // TODO реализация с помощью сигналов и слотов
    void attach(IObserver *obj) override;
    void detach(IObserver *obj) override;
signals:
    void changeSize();
private:
    std::vector<IObserver*> files;
    QString name;
    double size;
};


#endif //TSU_OLD_LAB_1_PUBLISHER_H
