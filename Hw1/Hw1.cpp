#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    MyString a("Hello");
    MyString b("world");

    a++;
    a.print();

    a--;
    a.print();

    a += " world";
    a.print();

    a -= "lo";
    a.print();

    cout << (a == b) << endl;
    cout << (a > b) << endl;
}
