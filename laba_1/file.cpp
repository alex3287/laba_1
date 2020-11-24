#include <QTextStream>
#include "file.h"
QTextStream out(stdout);

File::File(QString name): name(name){}
void File::update_size(int file_size)
{
    this -> file_size = file_size;
    out<<"Size at "<<name<<" is now "<<file_size<<endl;
}
