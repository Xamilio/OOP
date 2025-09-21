#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    MyString text1("Hello");
    MyString text2("World");
    text1.print();
    text2.print();

    MyString copy = text1;
    copy.print();

    if (text1.MyStrStr("el"))
        cout << "Substring found in Hello\n";
    else
        cout << "Substring not found in Hello\n";

    cout << "Index of 'o' in World: " << text2.MyChr('o') << endl;
    cout << "Length of Hello: " << text1.MyStrLen() << endl;

    text1.MyStrCat(text2);
    cout << "After concatenation: ";
    text1.print();

    text1.MyDelChr('l');
    cout << "After deleting 'l': ";
    text1.print();

    int result = text2.MyStrCmp(copy);
    if (result == 0) cout << "World == Hello\n";
    else if (result < 0) cout << "World < Hello\n";
    else cout << "World > Hello\n";
}
