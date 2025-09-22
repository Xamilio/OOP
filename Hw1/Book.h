#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char title[50];
    char author[50];
    char genre[30];
    bool isTaken;

public:
    Book();
    Book(const char* t, const char* a, const char* g);
    Book(const Book& other);
    Book(Book&& other);
    ~Book();
    void print() const;
    void take();
    void giveBack();
    bool available() const;
};
