//
// Created by Александр Мангазеев on 24.04.2021.
//

#include "Publisher.h"

//Publisher::Publisher(QString n, double s): name(n), size(s) {}
Publisher::Publisher() {}


void Publisher::addFile(IObserver *obj) {
    files.push_back(obj);
    this->attach(obj);
}

void Publisher::removeFile(IObserver *obj) {
    this->detach(obj);
    files.erase(remove(files.begin(), files.end(), obj), files.end());
}

void Publisher::showLists() {
    QTextStream out(stdout);
    out<<"\n==================================="<<endl;
    out<<"\t\t\tList files"<<endl;
    int i=0;
    for (auto obj: files)
        out<<++i<<" File name: "<<obj->getName()<<", file size: "<<obj->getSize()<<endl;
    out<<"\t\t\tEND"<<endl;
    out<<"===================================\n"<<endl;
}

void Publisher::notify() {
    for (auto file: files)
        this->changeSize();
}

// TODO реализация с помощью сигналов и слотов

void Publisher::attach(IObserver *obj) {
    connect(this, &Publisher::changeSize, obj, &IObserver::updateSize);
}

void Publisher::detach(IObserver *obj) {
    QObject::disconnect(this, &Publisher::changeSize,
                        obj, &IObserver::updateSize);
}

