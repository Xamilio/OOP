#include "Group.h"
#include <cstring>

Group::Group()
{
    name = 0;
    list = 0;
    subList = 0;
    countOfStudents = 0;
    countOfSubs = 0;
}
Group::~Group()
{
    if (name) delete[] name;
    if (list) delete[] list;
    if (subList) delete[] subList;
}
void Group::setName(const char* n)
{
    if (name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name,n);
}
const char* Group::getName()
{
    return name;
}
void Group::setStudents(int c)
{
    if (list) delete[] list;
    countOfStudents = c;
    list = new Student[c];
}
Student& Group::getStudent(int index)
{
    return list[index];
}
int Group::getStudentCount()
{
    return countOfStudents;
}
void Group::setSubjects(int c)
{
    if (subList) delete[] subList;
    countOfSubs = c;
    subList = new Subject[c];
}
Subject& Group::getSubject(int index)
{
    return subList[index];
}
int Group::getSubjectCount()
{
    return countOfSubs;
}
