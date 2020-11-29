#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QList>
#include "file.h"
#include "client.h"
#include <typeinfo>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QTextStream in(stdin);
    QCoreApplication a(argc, argv);

// Сделаю для 2-х файлов, пока не могу хранить файлы в контейнере
// Файлы должны быть на диске созданы заранее
    QString fileName;
    QString fileName2;

    out<<"Enter file name 1"<<endl;
    in >> fileName;
    out<<"Enter file name 2"<<endl;
    in >> fileName2;
// Проверяем существование файла
    if ((!QFile(fileName).exists()) && (!QFile(fileName2).exists())) {
        qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
        return 1;
    }

//создаем объект наблюдатель
    Client files;

// создаем два пользовательских объекта типов File
    File file1(fileName);
    File file2(fileName2);

// тут программа будет работать вместо потоков использую while
    int first = 0;
    int second = 0;
    int flagFirst = first;
    int flagSecond = second;
    int flag = 1; // служит для окончания работы программы
    while (flag == 1) {
        out<<"Enter 1 for track first file or 0 for untrack"<<endl;
        in>>first;
        out<<"Enter 1 for track second file or 0 for untrack"<<endl;
        in>>second;
        // начинаю следить за 1 файлом
        if ((first == 1) && (flagFirst == 0)){
            files.attach(&file1);
            flagFirst = 1;
            out<<"start track "<<file1.printFileName()<<endl;
        }
        //перестаю следить за 1 файлом
        else if (flagFirst != first){
            files.detach(&file1);
            flagFirst = 0;
            out<<"stop track "<<file1.printFileName()<<endl;
        }
        if ((second == 1) && (flagSecond == 0)){
            files.attach(&file2);
            flagSecond = 1;
            out<<"start track "<<file2.printFileName()<<endl;
        }
        else if (flagSecond != second){
            files.detach(&file2);
            flagSecond = 0;
            out<<"stop track "<<file2.printFileName()<<endl;
        }
        files.size_change();
        // выбор на завершение или продолжение программы
        out<<"check fieles 1/0 (yes/no) "<<endl;
        in >> flag;
    }


// посмотрим на размер
//    files.size_change();
//    out<<endl;
//    int flag = 1;
//    while (true) {
//        out<<"check fieles 1/0 (yes/no) "<<endl;
//        in >> flag;
//        if (flag == 0)
//            break;
//        files.size_change();
//    }
//    files.detach(&file1);
//    files.size_change();

// тут может быть додумаюсь и тогда сделаю любое количество файлов
//    QVector <File*> myFiles;
//    int countNames = 0;
//    out<<"Enter number files for work"<<endl;
//    in >> countNames;
// Введем имена существующих файлов иначе прога остановится
//    QString tempName;
//    for (int i=0;i<countNames;i++){
//        out<<"Enter file name -> "<<endl;
//        in >> tempName;
// Проверяем существование файла
//        if (!QFile(tempName).exists()) {
//           qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
//           return 1;
//        }
//        File tempFile(tempName);
//        myFiles.push_back(&tempFile);
//    };


    QTimer::singleShot(1000,  &a, SLOT(quit()));
    return a.exec();
}
