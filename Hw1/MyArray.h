#pragma once
#include <iostream>
using namespace std;

class MyArray
{
    int* arr;
    int size;
public:
    MyArray();
    MyArray(int n);
    MyArray(const MyArray& other);
    MyArray(MyArray&& other);
    ~MyArray();

    MyArray& operator=(const MyArray& other);
    MyArray& operator=(MyArray&& other) ;
    int& operator[](int index);
    const int& operator[](int index) const;
    MyArray operator+(const MyArray& other) const;
    MyArray& operator++();
    MyArray& operator--();

    void PushBack(int value);
    void PopBack();
    void print() const;
};
