#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFileInfo>
#include "testqtimer.h"
#include <QTimer>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    // test QTimer
    TestQTimer my_timer;

    // test QString
    QString s = "Hello world!";
    out<<s << "  "<< endl;

    //test comand line
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

    QTimer::setInterval(1000, SIGNAL(timeout()), &a, SLOT(my_timer.set_file()));
    return a.exec();
}
