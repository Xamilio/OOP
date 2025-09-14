#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
private:
    char* name;
    Student* list;
    int countOfStudents;
    Subject* subList;
    int countOfSubs;
public:
    Group();
    ~Group();
    void setName(const char* n);
    const char* getName();
    void setStudents(int c);
    Student& getStudent(int index);
    int getStudentCount();
    void setSubjects(int c);
    Subject& getSubject(int index);
    int getSubjectCount();
};

