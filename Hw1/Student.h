#pragma once
class Student
{
private:
    char* name;
    int* marks;
    int size;
public:
    Student();
    ~Student();
    Student(const Student& other);
    void setName(const char* n);
    const char* getName();
    void setMarks(int s);
    void setMark(int index, int value);
    int getMark(int index);
    int getSize();
};



