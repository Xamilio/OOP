#include "Fraction.h"

Fraction::Fraction()
{
    numerator = rand() % 20;
    denominator = (rand() % 9) + 1;
    cout << "Конструктор по умолчанию: " << numerator << "/" << denominator << endl;
}

Fraction::Fraction(int a, int b) 
{
    numerator = a;
    if (b == 0) {
        cout << "Ошибка: знаменатель = 1" << endl;
        denominator = 1;
    }
    else {
        denominator = b;
    }
    cout << "Конструктор с параметрами: " << numerator << "/" << denominator << endl;
}

Fraction::~Fraction() 
{
    cout << "Деструктор: " << numerator << "/" << denominator << endl;
}

void Fraction::Print() const {
    cout << "Дробь: " << numerator << "/" << denominator << endl;
}

Fraction Fraction::Sum(const Fraction& b) const
{
    int num = numerator * b.denominator + b.numerator * denominator;
    int den = denominator * b.denominator;
    return Fraction(num, den);
}

Fraction Fraction::Sub(const Fraction& b) const 
{
    int num = numerator * b.denominator - b.numerator * denominator;
    int den = denominator * b.denominator;
    return Fraction(num, den);
}

Fraction Fraction::Mul(const Fraction& b) const
{
    int num = numerator * b.numerator;
    int den = denominator * b.denominator;
    return Fraction(num, den);
}

Fraction Fraction::Div(const Fraction& b) const
{
    int num = numerator * b.denominator;
    int den = denominator * b.numerator;
    return Fraction(num, den);
}
