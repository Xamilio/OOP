#include "MyArray.h"

int main()
{
    setlocale(LC_ALL, "ru");
    MyArray a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;
    MyArray b(2);
    b[0] = 4; b[1] = 5;
    cout << "Array a: "; a.print();
    cout << "Array b: "; b.print();

    MyArray c = a + b;
    cout << "a + b: "; c.print();
    ++a;
    cout << "a после ++ : "; a.print();
    --b;
    cout << "b после -- : "; b.print();
}
