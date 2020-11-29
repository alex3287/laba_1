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
    QString fileName;
    QString fileName2;

    out<<"Enter file name -> "<<endl;
    in >> fileName;
    out<<"Enter file name2 -> "<<endl;
    in >> fileName2;
    // Проверяем существование файла
    if (!QFile(fileName).exists()) {
       qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
       return 1;
    }
    // Создаем объект
//    QFileInfo fileinfo(nameFile);

    // Определяем размер файла с помощью метода size()
//    qint64 size = fileinfo.size();

   // Выводим результат
//    QString str = "The size is: %1 bytes";
//    out << str.arg(size) << endl;


    //создаем объект наблюдатель
    Client files;

    //создаем файлы
    File file1(fileName);
    File file2(fileName2);


    //начинаем следить за файлами
    files.attach(&file1);
    files.attach(&file2);

    files.size_change();
    out<<endl;
    int flag = 1;
    while (true) {
        out<<"check fieles 1/0 (yes/no) "<<endl;
        in >> flag;
        if (flag == 0)
            break;
        files.size_change();
    }

    //прекращаем следить за вторым файлом
//    QObject::disconnect(&files, &Client::size_change,
//                         &file2, &File::update_size);
//    files.size_change(34);

    QTimer::singleShot(1000,  &a, SLOT(quit()));
    return a.exec();
}
