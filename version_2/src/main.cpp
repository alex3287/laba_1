#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>

#include <vector>

#include "src/Publisher.h"
#include "src/File.h"

int main() {
    QTextStream out(stdout);
    QTextStream in(stdin);

// Вводим количество файлов fixme
    int countFiles = 3;
    out<<"Enter count files -> "<<endl;
    in >> countFiles;

//  Добавляем имена СУЩЕСТВУЮЩИХ файлов в вектор
    std::vector<QString> filesName;
    QString name = "";
    for (int i=0;i<countFiles;i++){
        out<<"Enter file name -> "<<endl;
        in >> name;
        filesName.push_back(name);
    }

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
        QFileInfo fileinfo(fn);
        qint64 size = fileinfo.size();
        File *file = new File(fn, size);
        Files.push_back(file);
    }

// проверка содержимого списка
    for (auto i: Files)
            out<<i->getName()<<" "<<i->getSize()<<endl;

// делаем подписку
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
    }
    return 0;
}