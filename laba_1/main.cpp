#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    // test QString
    QString s = "Hello world!";
    out<<s << "  "<< endl;

    //test comand line
    if (argc > 1){
        QString f1 = argv[1];
        out<<f1<<endl;
    }
    if (argc > 2){
        QString f2 = argv[2];
        out<<f2<<endl;
    }

    return a.exec();
}
