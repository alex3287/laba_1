#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    QString s = "Hello world!";
    out<<s << endl;

    return a.exec();
}
