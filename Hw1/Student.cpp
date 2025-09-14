#include "Student.h"
#include <cstring>

Student::Student()
{
    name = 0;
    marks = 0;
    size = 0;
}
Student::~Student()
{
    if (name) delete[] name;
    if (marks) delete[] marks;
}
void Student::setName(const char* n)
{
    if (name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name,n);
}
const char* Student::getName()
{
    return name;
}
void Student::setMarks(int s)
{
    if (marks) delete[] marks;
    size = s;
    marks = new int[s];
    for(int i=0;i<s;i++) marks[i]=0;
}
void Student::setMark(int index, int value)
{
    if(index>=0 && index<size) marks[index]=value;
}
int Student::getMark(int index)
{
    if(index>=0 && index<size) return marks[index];
    return 0;
}
int Student::getSize()
{
    return size;
}
