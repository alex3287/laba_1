#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFileInfo>
#include <QVector>
#include "file.h"
#include "client.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

//    test comand line
    if (argc > 1){
        // file name it is arg
        QString f1 = argv[1];
        out<<f1<<endl;
        // check correct file
        if (!QFile(f1).exists()) {
            qWarning("The file does not exist");
            return 1;
          }
        QFileInfo fileinfo(f1);
        qint64 size = fileinfo.size();
        QString str = "The size is: %1 bytes";
        out << str.arg(size) << endl;
    }
    if (argc > 2){
        QString f2 = argv[2];
        out<<f2<<endl;
    }


//     test pattern
    Client files;
    File f1("First");
    File f2("Second");
    files.attach(&f1);
    files.attach(&f2);
    files.change_size(124);
    files.change_size(500);
    files.detach(&f2);
    files.change_size(100);
    return a.exec();
}
