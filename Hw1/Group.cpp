#include "Group.h"
#include <iostream>
#include <cstring>
using namespace std;

Group::Group()
{
    name[0] = '\0';
    students = nullptr;
    countStudents = 0;
    subjects = nullptr;
    countSubjects = 0;
}

Group::Group(const char* n, int studCount, int subjCount)
{
    strncpy(name, n, 29);
    name[29] = '\0';

    countStudents = studCount;
    students = new Student[countStudents];

    countSubjects = subjCount;
    subjects = new Subject[countSubjects];
}

Group::~Group()
{
    delete[] students;
    delete[] subjects;
}

void Group::setStudent(int index, const Student& s)
{
    if (index >= 0 && index < countStudents)
        students[index] = s;
}

Student& Group::getStudent(int index)
{
    return students[index];
}

void Group::setSubject(int index, const Subject& s)
{
    if (index >= 0 && index < countSubjects)
        subjects[index] = s;
}

Subject& Group::getSubject(int index)
{
    return subjects[index];
}

void Group::printMarks() const
{
    cout << "Таблица оценок:\n";
    for (int i = 0; i < countStudents; i++)
    {
        cout << students[i].getName() << ": ";
        for (int j = 0; j < countSubjects; j++)
            cout << students[i].getMark(j) << " ";
        cout << endl;
    }
}

void Group::printAverages() const
{
    cout << "Средние оценки студентов:\n";
    for (int i = 0; i < countStudents; i++)
        cout << students[i].getName() << " = " << students[i].average() << endl;
}