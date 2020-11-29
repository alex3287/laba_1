#include "client.h"

void Client::attach(File *file)
{
    QObject::connect(this, &Client::size_change,
                         file, &File::update_size);
}

void Client::detach(File *file)
{
    QObject::disconnect(this, &Client::size_change,
                         file, &File::update_size);
}
