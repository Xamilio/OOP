#include <iostream>
#include "Group.h"
using namespace std;

int main()
{
    Group g("Group A", 2, 2);
    Subject s1, s2;
    s1.setName("Math");
    s2.setName("Physics");
    g.setSubject(0, s1);
    g.setSubject(1, s2);
    Student st1("Ivan", 2);
    Student st2("Oleg", 2);
    st1.setMark(0, 5);
    st1.setMark(1, 4);
    st2.setMark(0, 3);
    st2.setMark(1, 5);
    g.setStudent(0, st1);
    g.setStudent(1, st2);
    g.printMarks();
    g.printAverages();
}
