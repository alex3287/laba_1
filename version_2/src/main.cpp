#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>

#include <vector>

#include "src/Publisher.h"
#include "src/File.h"

QTextStream out(stdout);
QTextStream in(stdin);

int main() {
//    QString first="123.txt";
//    QFileInfo fileinfo(first);
//    qint64 size = fileinfo.size();
//    File file1(first,size);
//
//    Publisher publisher;
//
//    publisher.addFile(&file1);
//
//
//    out<<file1.getName()<<" "<<file1.getSize()<<endl;
//
//    publisher.showLists();
//    int n=0;
//    out<<"-> "<<endl;
//    in>>n;
//    publisher.notify();
//    publisher.showLists();


// Вводим количество файлов fixme
//    int countFiles = 3;
//    out<<"Enter count files -> "<<endl;
//    in >> countFiles;

//  Добавляем имена СУЩЕСТВУЮЩИХ файлов в вектор
//    QString first="123.txt", second="11.txt", third="22.db";
    std::vector<QString> filesName;
    filesName.push_back("123.txt");
    filesName.push_back("11.txt");
    filesName.push_back("22.db");
//    QString name = ""; fixme
//    for (int i=0;i<countFiles;i++){
//        out<<"Enter file name -> "<<endl;
//        in >> name;
//        filesName.push_back(name);
//    }

//    проверяю список имен
//    for (auto fn: filesName){
//        out<<fn<<endl;
//    }

// Проверяем существование файла
// если файл не найден, то выводим предупреждение и завершаем работу программы
    for (auto fname: filesName)
    if (!QFile(fname).exists()) {
        qWarning("The file does not exist");
        return 1;
    }

//создаем объект наблюдатель
    Publisher publisher;

// создаем пустой список объектов типа File
    std::vector<File*> Files;

// вычисляем размеры файлов и добавляем их в список
    for (auto fn: filesName) {
//        QFileInfo fileinfo(filesName[0]);
//        qint64 size = fileinfo.size();
//        File file1(filesName[0],size);
//        QFileInfo fileinfo1(filesName[1]);
//        size = fileinfo1.size();
//        File file2(filesName[1], size);
//        QFileInfo fileinfo2(filesName[2]);
//        size = fileinfo1.size();
//        File file3(filesName[2], size);

        QFileInfo fileinfo(fn);
        qint64 size = fileinfo.size();
        File *file = new File(fn, size);
        Files.push_back(file);
    }

// проверка содержимого списка
    for (auto i: Files)
            out<<i->getName()<<" "<<i->getSize()<<endl;

// делаем подписку
//        publisher.addFile(&file1);
//        publisher.addFile(&file2);
//        publisher.addFile(&file3);
    for (auto file: Files) {
        publisher.addFile(file);
    }

//    программа начинает следить за файлами пока ее не остановят
    int flag = 1, number = 0; // untrackedFiles[3] {0,0,0};
    std::vector<File*> untrackedFiles;
    while (flag) {
        publisher.notify();
        //список отслеживаемых файлов
        publisher.showLists();
        //возможность прекращения слежки
        out << "Enter number file for untracked or 0 for continue -> " << endl;
        in >> number;
        if ((number > 0) && (number <= Files.size())){
            out<<"untracked for file name:"<<Files[number-1]->getName()<<endl;
            untrackedFiles.push_back(Files[number-1]);
            publisher.removeFile(Files[number-1]);
        }

//        возможность возобновить слежку
        if (untrackedFiles.size()>0){
            int i = 0;
            out<<"\t\t\t untrackedFiles"<<endl;
            for (auto fn: untrackedFiles)
                out<<++i<<") "<<fn->getName()<<endl; //TODO check i
            out << "Enter number file for track or 0 for continue -> " << endl;
            in >> number;
            if ((number > 0) && (number <= untrackedFiles.size())){
                out<<"tracked for file name:"<<untrackedFiles[number-1]->getName()<<endl;
                publisher.addFile(untrackedFiles[number-1]);
                untrackedFiles.erase(remove(untrackedFiles.begin(), untrackedFiles.end(), untrackedFiles[number-1]), untrackedFiles.end());
            }
        }
        out << "Enter 0 for finish program or any number for continue -> " << endl;
        in >> flag;

//        }
    }


//    for (auto i: Files)
//        out<<i->getName()<<" "<<i->getSize()<<endl;
//    out<<file1.getName()<<" "<<file1.getSize()<<endl;
//    publisher.showLists();
//    publisher.removeFile(Files[1]);
//    publisher.notify();
//    for (auto i: Files)
//        out<<i->getName()<<" "<<i->getSize()<<endl;
//    out<<file1.getName()<<" "<<file1.getSize()<<endl;
//    publisher.showLists();
    return 0;
}