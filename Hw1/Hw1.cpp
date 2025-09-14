#include <iostream>
#include "Group.h"
using namespace std;

int main()
{
    Group g;
    g.setName("Group1");
    g.setStudents(2);
    g.setSubjects(2);

    g.getSubject(0).setName("Math");
    g.getSubject(1).setName("Physics");

    g.getStudent(0).setName("Ivan");
    g.getStudent(0).setMarks(g.getSubjectCount());
    g.getStudent(0).setMark(0,5);
    g.getStudent(0).setMark(1,4);

    g.getStudent(1).setName("Petr");
    g.getStudent(1).setMarks(g.getSubjectCount());
    g.getStudent(1).setMark(0,3);
    g.getStudent(1).setMark(1,5);

    for(int i=0;i<g.getStudentCount();i++)
    {
        cout<<g.getStudent(i).getName()<<": ";
        for(int j=0;j<g.getSubjectCount();j++)
            cout<<g.getSubject(j).getName()<<"="<<g.getStudent(i).getMark(j)<<" ";
        cout<<endl;
    }
}
