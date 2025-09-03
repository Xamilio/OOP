#include <iostream>
#include <cstring>
using namespace std;

class Car
{
    char* model;
    char* color;
    char* country;
    int year;
    double price;

public:
    Car()
    {
        model = color = country = nullptr;
        year = 0;
        price = 0;
    }

    Car(const char* m, const char* c, const char* co, int y, double p)
    {
        model = new char[strlen(m) + 1];
        strcpy_s(model, strlen(m) + 1, m);

        color = new char[strlen(c) + 1];
        strcpy_s(color, strlen(c) + 1, c);

        country = new char[strlen(co) + 1];
        strcpy_s(country, strlen(co) + 1, co);

        year = y;
        price = p;
    }
    ~Car()
    {
        delete[] model;
        delete[] color;
        delete[] country;
    }

    char* getModel()
    {
        return model;
    }
    char* getColor()
    {
        return color;
    }
    char* getCountry()
    {
        return country;
    }
    int getYear()
    {
        return year;
    }
    double getPrice()
    {
        return price;
    }

    void setModel(const char* m)
    {
        delete[] model;
        model = new char[strlen(m) + 1];
        strcpy_s(model, strlen(m) + 1, m);
    }

    void setColor(const char* c)
    {
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy_s(color, strlen(c) + 1, c);
    }

    void setCountry(const char* co)
    {
        delete[] country;
        country = new char[strlen(co) + 1];
        strcpy_s(country, strlen(co) + 1, co);
    }

    void setYear(int y)
    {
        year = y;
    }

    void setPrice(double p)
    {
        price = p;
    }

    void init()
    {
        char b[100];

        cout << "Enter Model: ";
        cin.getline(b, 100);
        setModel(b);

        cout << "Enter Color: ";
        cin.getline(b, 100);
        setColor(b);

        cout << "Enter Country: ";
        cin.getline(b, 100);
        setCountry(b);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Price: ";
        cin >> price;
    }

    void print()
    {
        cout << "Car Info:" << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Country: " << country << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

int main()
{
    Car a1;
    a1.init();
    a1.print();

    Car a2("Audi", "Black", "Germany", 2020, 20000);
    a2.print();
}
