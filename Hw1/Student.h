#pragma once
class Student
{
public:
    char* name;
    int* marks;
    int size;
    Student();
    ~Student();
    void setName(const char* n);
    void setMarks(int s);
};


