#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Context
{
public:
    int input;
    string output;

    Context(int input)
    {
        this->input = input;
    }

    Context(string output)
    {
        this->input = 0;
        this->output = output;
    }
};

class Expression
{
public:
    virtual void interpret(Context& context) = 0;
};

class RomanExpression : public Expression
{
protected:
    virtual string one() = 0;
    virtual string four() = 0;
    virtual string five() = 0;
    virtual string nine() = 0;
    virtual int multiplier() = 0;

public:
    void interpret(Context& context) override
    {
        int value = context.input / multiplier();
        context.input %= multiplier();

        if (value == 9)
        {
            context.output += nine();
        }
        else if (value >= 5)
        {
            context.output += five();

            for (int i = 0; i < value - 5; i++)
            {
                context.output += one();
            }
        }
        else if (value == 4)
        {
            context.output += four();
        }
        else
        {
            for (int i = 0; i < value; i++)
            {
                context.output += one();
            }
        }
    }
};

class Thousand : public RomanExpression
{
protected:
    string one() override
    {
        return "M";
    }

    string four() override
    {
        return "";
    }

    string five() override
    {
        return "";
    }

    string nine() override
    {
        return "";
    }

    int multiplier() override
    {
        return 1000;
    }
};

class Hundred : public RomanExpression
{
protected:
    string one() override
    {
        return "C";
    }

    string four() override
    {
        return "CD";
    }

    string five() override
    {
        return "D";
    }

    string nine() override
    {
        return "CM";
    }

    int multiplier() override
    {
        return 100;
    }
};

class Ten : public RomanExpression
{
protected:
    string one() override
    {
        return "X";
    }

    string four() override
    {
        return "XL";
    }

    string five() override
    {
        return "L";
    }

    string nine() override
    {
        return "XC";
    }

    int multiplier() override
    {
        return 10;
    }
};

class One : public RomanExpression
{
protected:
    string one() override
    {
        return "I";
    }

    string four() override
    {
        return "IV";
    }

    string five() override
    {
        return "V";
    }

    string nine() override
    {
        return "IX";
    }

    int multiplier() override
    {
        return 1;
    }
};

int romanToInt(string s)
{
    vector<pair<string, int>> roman =
    {
        {"M",1000}, {"CM",900}, {"D",500}, {"CD",400},
        {"C",100}, {"XC",90}, {"L",50}, {"XL",40},
        {"X",10}, {"IX",9}, {"V",5}, {"IV",4}, {"I",1}
    };

    int result = 0;

    for (auto& p : roman)
    {
        while (s.find(p.first) == 0)
        {
            result += p.second;
            s.erase(0, p.first.length());
        }
    }

    return result;
}

int main()
{
    int number = 1994;
    Context context(number);

    vector<Expression*> tree;

    tree.push_back(new Thousand());
    tree.push_back(new Hundred());
    tree.push_back(new Ten());
    tree.push_back(new One());

    for (auto exp : tree)
    {
        exp->interpret(context);
    }

    cout << "Arabic: " << number << " -> Roman: " << context.output << endl;

    string roman = "MCMXCIV";

    cout << "Roman: " << roman
        << " -> Arabic: " << romanToInt(roman) << endl;
}
