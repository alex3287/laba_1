#include <QCoreApplication>
#include <QTextStream>

QTextStream out(stdout);

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    out<<"hello world"<<endl;
    return a.exec();
}
