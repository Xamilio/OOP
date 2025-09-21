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
Group::Group(const Group& other)
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

	count_of_students = other.count_of_students;
	count_of_subjects = other.count_of_subjects;

	if (count_of_students > 0)
	{
		students = new Student[count_of_students];
	}
	else
	{
		students = nullptr;
	}

	if (count_of_subjects > 0)
	{
		subjects = new Subject[count_of_subjects];
	}
	else
	{
		subjects = nullptr;
	}

	for (int i = 0; i < count_of_students; i++)
	{
		students[i] = other.students[i];
	}

	for (int i = 0; i < count_of_subjects; i++)
	{
		subjects[i] = other.subjects[i];
	}
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

