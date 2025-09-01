#include <iostream>
using namespace std;

class Fraction
{
    int numerator;  
    int denominator;

public:
    void Init(int a, int b)
    {
        numerator = a;
        if (b == 0) {
            cout << "Ошибка: знаменатель = 1" << endl;
            denominator = 1;
        }
        else {
            denominator = b;
        }
    }

    void Init()
    {
        numerator = rand() % 20;
        denominator = (rand() % 9) + 1;
    }

    void Print()
    {
        cout << "Дробь: " << numerator << "/" << denominator << endl;
    }

    void Sum(Fraction& b)
    {
        int num = numerator * b.denominator + b.numerator * denominator;
        int den = denominator * b.denominator;
        cout << "Сумма: " << num << "/" << den << endl;
    }

    void Sub(Fraction& b)
    {
        int num = numerator * b.denominator - b.numerator * denominator;
        int den = denominator * b.denominator;
        cout << "Разность: " << num << "/" << den << endl;
    }

    void Mul(Fraction& b)
    {
        int num = numerator * b.numerator;
        int den = denominator * b.denominator;
        cout << "Произведение: " << num << "/" << den << endl;
    }

    void Div(Fraction& b)
    {
        int num = numerator * b.denominator;
        int den = denominator * b.numerator;
        cout << "Частное: " << num << "/" << den << endl;
    }
};

int main()
{
    Fraction A, B;

    A.Init(2, 3);
    A.Print();
    B.Init(3, 4);
    B.Print();
    A.Sum(B);
    A.Sub(B);
    A.Mul(B);
    A.Div(B);
}
