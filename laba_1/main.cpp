#include <QCoreApplication>
#include <QTextStream>
#include "file.h"
#include "client.h"


int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QCoreApplication a(argc, argv);

    //создаем объект наблюдатель
    Client files;

    //создаем файлы
    File file1("fiel1.txt");
    File file2("file2.txt");

    //начинаем следить за файлами
    QObject::connect(&files, &Client::size_change,
                         &file1, &File::update_size);
    QObject::connect(&files, &Client::size_change,
                         &file2, &File::update_size);

    files.size_change(23);
    out<<endl;

    //прекращаем следить за вторым файлом
    QObject::disconnect(&files, &Client::size_change,
                         &file2, &File::update_size);
    files.size_change(34);

    return a.exec();
}
