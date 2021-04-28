//
// Created by Александр Мангазеев on 25.04.2021.
//

#include "File.h"

File::File(QString name, qint64 size) {
    this->name = name;
    this->size = size;
//    publisher = subj;
}

qint64 File::getSize() {
    return size;
}

QString File::getName() {
    return name;
}

void File::updateSize() {
    qint64 newSize = newFileSize(name);
    if (size != newSize)
        size = newSize;
}

qint64 File::newFileSize(QString n) {
    QFileInfo fileinfo(n);
    qint64 fileSize = fileinfo.size();
    return fileSize;
}

void File::setSize(qint64 newSize) {
    size = newSize;
}

void File::setName(QString newName) {
    name = newName;
}
