#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction();                 
    Fraction(int a, int b);
    ~Fraction();                

    void Print() const;

    Fraction Sum(const Fraction& b) const;
    Fraction Sub(const Fraction& b) const;
    Fraction Mul(const Fraction& b) const;
    Fraction Div(const Fraction& b) const;
};

