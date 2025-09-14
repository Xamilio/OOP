#include "Subject.h"
#include <cstring>

Subject::Subject()
{
    name = 0;
}
Subject::~Subject()
{
    if (name) delete[] name;
}
void Subject::setName(const char* n)
{
    if (name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name,n);
}
const char* Subject::getName()
{
    return name;
}
