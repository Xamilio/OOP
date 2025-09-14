#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
private:
    char name[30];
    Student* students;
    int countStudents;

    Subject* subjects;
    int countSubjects;

public:
    Group();
    Group(const char* n, int studCount, int subjCount);
    ~Group();

    void setStudent(int index, const Student& s);
    Student& getStudent(int index);

    void setSubject(int index, const Subject& s);
    Subject& getSubject(int index);

    void printMarks() const;
    void printAverages() const;
};
