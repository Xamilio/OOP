#include "Student.h"
#include <cstring>

Student::Student()
{
    name[0] = '\0';
    marks = nullptr;
    size = 0;
}

Student::Student(const char* n, int subjCount)
{
    strncpy(name, n, 29);
    name[29] = '\0';
    size = subjCount;
    marks = new int[size];
    for (int i = 0; i < size; i++) marks[i] = 0;
}

Student::~Student()
{
    delete[] marks;
}

void Student::setName(const char* n)
{
    strncpy(name, n, 29);
    name[29] = '\0';
}

const char* Student::getName() const
{
    return name;
}

void Student::setMark(int index, int mark)
{
    if (index >= 0 && index < size)
        marks[index] = mark;
}

int Student::getMark(int index) const
{
    if (index >= 0 && index < size)
        return marks[index];
    return -1;
}

double Student::average() const
{
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += marks[i];
    return (double)sum / size;
}