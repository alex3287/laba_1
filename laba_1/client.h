#ifndef CLIENT_H
#define CLIENT_H

#include "subject.h"

class Client : public Subject
{
public:
    void attach(File *file);
    void detach(File *file);
};

#endif // CLIENT_H
