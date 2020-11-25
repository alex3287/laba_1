#include "subject.h"

void Subject::attach(File *file)
{
    list.push_back(file);
}

void Subject::detach(File *file)
{
    list.erase(std::remove(list.begin(), list.end(), file), list.end());
}

void Subject::notify_size(int file_size)
{
    for (QVector<File*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if (*iter != 0)
        {
            (*iter)->update_size(file_size);
        }
    }
}
