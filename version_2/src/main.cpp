#include <iostream>
#include <QString>
#include <QTextStream>

#include <QFile>
#include <QFileInfo>

#include "src/Publisher.h"
#include "src/File.h"

int main() {
    QTextStream out(stdout);
    QTextStream in(stdin);

// Сделаю для 1 файла
// Файл должн быть на диске создан заранее
    QString fileName = "123.txt";

//    TODO раскомитеть
//    out<<"Enter file name -> "<<endl;
//    in >> fileName;

// Проверяем существование файла
    if (!QFile(fileName).exists()) {
        qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
        return 1;
    }
// вычисляем размер файла
    QFileInfo fileinfo(fileName);
    qint64 size = fileinfo.size();

//создаем объект наблюдатель
    Publisher publisher;

// создаем пользовательский объект типа File
    File file1(fileName, size);
    out<<file1.getName()<<" "<<file1.getSize()<<endl;

// тестируем сигналы и слоты
    publisher.attach(&file1);
    publisher.changeSize();
    out<<file1.getName()<<" "<<file1.getSize()<<endl;
    publisher.detach(&file1);
    publisher.changeSize();

    out<<file1.getName()<<" "<<file1.getSize()<<endl;
// проверка содержимого подписчиков
//    publisher.addFile(&file1);
//    publisher.showLists();
//    publisher.removeFile(&file1);
//    publisher.showLists();

//    QTimer::singleShot(1000,  &a, SLOT(quit()));
    return 0;
}
