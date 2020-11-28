#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QTimer>
#include <iostream>
#include "file.h"
#include "client.h"


int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QTextStream in(stdin);
    QCoreApplication a(argc, argv);

    //получаем имя файла от пользователя
    QString nameFile;

    out<<"Enter file name -> "<<endl;
    in >> nameFile;
    // Проверяем существование файла
    if (!QFile(nameFile).exists()) {
       qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
       return 1;
    }
    // Создаем объект
    QFileInfo fileinfo(nameFile);

    // Определяем размер файла с помощью метода size()
    qint64 size = fileinfo.size();

   // Выводим результат
    QString str = "The size is: %1 bytes";
    out << str.arg(size) << endl;


    //создаем объект наблюдатель
    Client files;

    //создаем файлы
    File file1(nameFile);
    File file2("file2.txt");


    //начинаем следить за файлами
    QObject::connect(&files, &Client::size_change,
                         &file1, &File::update_size);
    QObject::connect(&files, &Client::size_change,
                         &file2, &File::update_size);

//    files.size_change(size);
    out<<endl;
    int flag = 1;
    while (true) {
        // Создаем объект
        QFileInfo fileinfo(nameFile);

        // Определяем размер файла с помощью метода size()
        qint64 size = fileinfo.size();
        size = fileinfo.size();
        files.size_change(size);
        out<<"check fieles 1/0 (yes/no) "<<endl;
        in >> flag;
        if (flag == 0)
            break;

    }

    //прекращаем следить за вторым файлом
    QObject::disconnect(&files, &Client::size_change,
                         &file2, &File::update_size);
    files.size_change(34);

    QTimer::singleShot(2000,  &a, SLOT(quit()));
    return a.exec();
}
