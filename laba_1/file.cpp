#include "file.h"
#include "client.h"
#include <QTextStream>
#include <QFileInfo>


QTextStream out(stdout);
QTextStream in(stdin);
File::File(QString name): name(name){}

Client *ptrClient = new(Client);

// Печатыем имя файла
QString File::printFileName()
{
    return name;
}

// Обновляем размер файла
void File::update_size(void)
{
    int newSize = newFileSize();
    if (fileSize != newSize){
        fileSize = newSize;
        emit ptrClient -> size_change();
}
    out<<"Size at "<<name<<" is now "<<fileSize<<endl;
}

// Получаем размер файла
int File::newFileSize(void)
{
    // Создаем объект
    QFileInfo fileinfo(name);

    // Определяем размер файла с помощью метода size()
    qint64 size = fileinfo.size();
    return size;
}
