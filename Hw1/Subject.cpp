#include "Subject.h"
#include <cstring>

Subject::Subject()
{
    name[0] = '\0';
}

void Subject::setName(const char* n)
{
    strncpy(name, n, 29);
    name[29] = '\0';
}

const char* Subject::getName() consts
{
    return name;
}
