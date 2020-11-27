#include "file.h"
#include "client.h"
#include <QTextStream>

QTextStream out(stdout);

File::File(QString name): name(name){}

Client *ptrClient = new(Client);

void File::update_size(int newFileSize)
{
    if (fileSize != newFileSize){
        fileSize = newFileSize;
        emit ptrClient -> size_change(newFileSize);
    }
    out<<"Size at "<<name<<" is now "<<fileSize<<endl;
}
