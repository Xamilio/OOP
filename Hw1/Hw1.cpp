#include <iostream>
#include <cstring>
using namespace std;

class Laptop
{
    char* model;
    double size;
    char* color;
    double price;

public:
    Laptop();
    Laptop(const char* m);
    Laptop(const char* m, double s);
    Laptop(const char* m, double s, const char* c);
    Laptop(const char* m, double s, const char* c, double p);
    ~Laptop();

    void print() const;
};

Laptop::Laptop()
{
    model = nullptr;
    size = 0.0;
    color = nullptr;
    price = 0;
}

Laptop::Laptop(const char* m)
{
    model = new char[strlen(m) + 1];
    strcpy(model, m);
    size = 0.0;
    color = nullptr;
    price = 0;
}

Laptop::Laptop(const char* m, double s) : Laptop(m)
{
    size = s;
}

Laptop::Laptop(const char* m, double s, const char* c) : Laptop(m, s)
{
    color = new char[strlen(c) + 1];
    strcpy(color, c);
}

Laptop::Laptop(const char* m, double s, const char* c, double p) : Laptop(m, s, c)
{
    price = p;
}

Laptop::~Laptop()
{
    delete[] model;
    delete[] color;
}

void Laptop::print() const
{
    cout << "Model: " << (model ? model : "N/A") << endl;
    cout << "Size: " << size << endl;
    cout << "Color: " << (color ? color : "N/A") << endl;
    cout << "Price: $" << price << endl;
}

int main()
{
    Laptop l1("MacBook Pro", 15.6, "Gray", 2499.99);
    l1.print();
}
