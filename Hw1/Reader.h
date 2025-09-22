#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Reader {
    char name[50];
    int id;
    int booksTaken;

public:
    Reader();
    Reader(const char* n, int i);
    Reader(const Reader& other);
    Reader(Reader&& other) noexcept;
    ~Reader();
    void print() const;
    void takeBook();û
    void returnBook();
};
