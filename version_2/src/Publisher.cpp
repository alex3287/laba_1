//
// Created by Александр Мангазеев on 24.04.2021.
//

#include "Publisher.h"

//Publisher::Publisher(QString n, double s): name(n), size(s) {}
Publisher::Publisher() {}
//double Publisher::getSize() {
//    return size;
//}
//
//QString Publisher::getName() {
//    return name;
//}

void Publisher::addFile(IObserver *obj) {
    files.push_back(obj);
}

void Publisher::removeFile(IObserver *obj) {
    files.erase(remove(files.begin(), files.end(), obj), files.end());
}

void Publisher::showLists() {
    QTextStream out(stdout);
    for (auto obj: files)
        out<<obj->getName()<<endl;
}

// TODO реализация с помощью сигналов и слотов

void Publisher::attach(IObserver *obj) {
    connect(this, &Publisher::changeSize, obj, &IObserver::updateSize);
}

void Publisher::detach(IObserver *obj) {
    QObject::disconnect(this, &Publisher::changeSize,
                        obj, &IObserver::updateSize);
}

