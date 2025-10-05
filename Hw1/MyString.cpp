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

MyString::MyString(std::initializer_list<char> list)
{
    length = static_cast<int>(list.size());
    str = new char[length + 1];

    int i = 0;
    for (char c : list)
    {
        str[i++] = c;
    }
    str[length] = '\0';
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

MyString& MyString::operator+=(const char* s)
{
    int la = strlen(str);
    int lb = strlen(s);
    char* buf = new char[la + lb + 1];
    strcpy_s(buf, la + lb + 1, str);
    strcat_s(buf, la + lb + 1, s);
    delete[] str;
    str = buf;
    length = la + lb;
    return *this;
}

MyString& MyString::operator-=(const char* s)
{
    char* pos = strstr(str, s);
    if (!pos) return *this;

    int start = pos - str;
    int lsub = strlen(s);
    int newlen = length - lsub;
    char* buf = new char[newlen + 1];

    strncpy_s(buf, newlen + 1, str, start);
    strcpy_s(buf + start, newlen - start + 1, str + start + lsub);

    delete[] str;
    str = buf;
    length = newlen;
    return *this;
}

bool MyString::operator==(const MyString& other) const
{
    return strcmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other) const
{
    return !(*this == other);
}

bool MyString::operator>(const MyString& other) const
{
    return strcmp(str, other.str) > 0;
}

bool MyString::operator<(const MyString& other) const
{
    return strcmp(str, other.str) < 0;
}

MyString MyString::operator++(int)
{
    MyString temp(*this);
    char* buf = new char[length + 2];
    strcpy_s(buf, length + 2, str);
    buf[length] = '!';
    buf[length + 1] = '\0';
    delete[] str;
    str = buf;
    length++;
    return temp;
}

MyString MyString::operator--(int)
{
    if (length == 0) return *this;
    MyString temp(*this);
    length--;
    char* buf = new char[length + 1];
    strncpy_s(buf, length + 1, str, length);
    buf[length] = '\0';
    delete[] str;
    str = buf;
    return temp;
}

