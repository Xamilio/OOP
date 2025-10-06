#pragma once
#include <string>
#include <iostream>
using namespace std;

class Worker {
    string name;
    string printText;
public:
    Worker();
    Worker(const string& n, const string& text);
    string GetName() const;
    string GetText() const;
    void PrintInfo() const;
};
