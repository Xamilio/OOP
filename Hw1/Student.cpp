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
Student::Student(const Student& other)
{
    if (other.name)
    {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }
    else
    {
        name = nullptr;
    }

    count_of_marks = other.count_of_marks;

    if (count_of_marks > 0 && other.marks)
    {
        marks = new int[count_of_marks];
        for (int i = 0; i < count_of_marks; i++)
        {
            marks[i] = other.marks[i];
        }
    }
    else
    {
        marks = nullptr;
    }
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

