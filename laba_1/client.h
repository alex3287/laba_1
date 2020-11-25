#ifndef CLIENT_H
#define CLIENT_H
#include "subject.h"

class Client : public Subject
{
public:
    void change_size(int file_size);
};

#endif // CLIENT_H
