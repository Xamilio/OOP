#include <iostream>
#include <cstring>
using namespace std;

class RulonOboev
{
public:
    char* name;
    double width;
    double length;
    double price;

    RulonOboev(const char* n = "", double w = 0, double l = 0, double p = 0)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        width = w;
        length = l;
        price = p;
    }

    ~RulonOboev()
    {
        delete[] name;
    }

    double getArea()
    {
        return width * length;
    }
};

class Komnata
{
public:
    char* name;
    double length;
    double width;
    double height;
    bool kleyitPotolok;

    Komnata(const char* n = "", double dl = 0, double w = 0, double h = 0, bool potolok = false)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        length = dl;
        width = w;
        height = h;
        kleyitPotolok = potolok;
    }

    ~Komnata()
    {
        delete[] name;
    }

    double getWallArea()
    {
        return 2 * (length + width) * height;
    }

    double getCeilArea()
    {
        if (kleyitPotolok)
        {
            return length * width;
        }
        return 0;
    }

    double getTotalArea()
    {
        return getWallArea() + getCeilArea();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int nRooms;
    cout << "Введите количество комнат: ";
    cin >> nRooms;

    Komnata* rooms = new Komnata[nRooms];
    for (int i = 0; i < nRooms; i++)
    {
        char temp[100];
        double dl, w, h;
        int potolok;
        cout << "Комната " << i + 1 << ": введите название, длину, ширину, высоту и (1 - клеим потолок, 0 - нет): ";
        cin >> temp >> dl >> w >> h >> potolok;

        rooms[i] = Komnata(temp, dl, w, h, potolok);
    }

    char tempR[100];
    double rw, rl, price;
    cout << "Введите параметры рулона (название, ширина, длина, цена): ";
    cin >> tempR >> rw >> rl >> price;

    RulonOboev rulon(tempR, rw, rl, price);

    double totalArea = 0;
    for (int i = 0; i < nRooms; i++)
    {
        totalArea += rooms[i].getTotalArea();
    }

    double areaPerRulon = rulon.getArea();
    int needed = (int)ceil(totalArea / areaPerRulon);

    cout << "Общая площадь оклейки: " << totalArea << " м^2\n";
    cout << "Площадь одного рулона: " << areaPerRulon << " м^2\n";
    cout << "Нужно рулонов: " << needed << "\n";
    cout << "Стоимость: " << needed * rulon.price << "\n";

    delete[] rooms;
}
