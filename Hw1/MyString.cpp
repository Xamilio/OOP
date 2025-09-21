#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

MyString::MyString()
{
    length = 80;
    str = new char[length] {};
}

MyString::MyString(int s)
{
    length = s;
    str = new char[length] {};
}

MyString::MyString(const char* txt)
{
    length = strlen(txt);
    str = new char[length + 1];
    strcpy_s(str, length + 1, txt);
}

MyString::~MyString()
{
    delete[] str;
    str = nullptr;
    length = 0;
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);
}

MyString::MyString(MyString&& other)
{
    str = other.str;
    length = other.length;
    other.str = nullptr;
    other.length = 0;
}

void MyString::print()
{
    cout << str << "\n";
}

void MyString::MyStrcpy(MyString& obj)
{
    if (this == &obj) return;
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* subs)
{
    return strstr(str, subs) != nullptr;
}

int MyString::MyChr(char ch)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ch) return i;
    }
    return -1;
}

int MyString::MyStrLen()
{
    return (int)strlen(str);
}

void MyString::MyStrCat(MyString& b)
{
    int la = strlen(str);
    int lb = strlen(b.str);
    char* buf = new char[la + lb + 1];
    strcpy_s(buf, la + lb + 1, str);
    strcat_s(buf, la + lb + 1, b.str);
    delete[] str;
    str = buf;
    length = la + lb;
}

void MyString::MyDelChr(char c)
{
    int cnt = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) cnt++;
    }
    char* buf = new char[cnt + 1];
    int k = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) buf[k++] = str[i];
    }
    buf[k] = '\0';
    delete[] str;
    str = buf;
    length = cnt;
}

int MyString::MyStrCmp(MyString& b)
{
    int r = strcmp(str, b.str);
    if (r < 0) return -1;
    if (r > 0) return 1;
    return 0;
}
