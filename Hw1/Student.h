#pragma once
class Student
{
private:
    char name[30];
    int* marks;
    int size;

public:
    Student();
    Student(const char* n, int subjCount);
    ~Student();

    void setName(const char* n);
    const char* getName() const;

    void setMark(int index, int mark);
    int getMark(int index) const;

    double average() const;
};

