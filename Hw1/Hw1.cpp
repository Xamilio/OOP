#include <iostream>
#include <cmath>
using namespace std;

class RulonOboev
{
public:
    char name[20];
    double width;
    double length;
    double price;

    RulonOboev(const char* n = "", double w = 0, double l = 0, double p = 0)
    {
        int i = 0;
        for (; n[i] != '\0' && i < 19; i++)
        {
            name[i] = n[i];
        }
        name[i] = '\0';
        width = w;
        length = l;
        price = p;
    }

    double getArea() const
    {
        return width * length;
    }
};

class Komnata
{
public:
    char name[20];
    double length;
    double width;
    double height;
    bool kleyitPotolok;

    Komnata(const char* n = "", double dl = 0, double w = 0, double h = 0, bool potolok = false)
    {
        int i = 0;
        for (; n[i] != '\0' && i < 19; i++)
        {
            name[i] = n[i];
        }
        name[i] = '\0';
        length = dl;
        width = w;
        height = h;
        kleyitPotolok = potolok;
    }

    double getWallArea() const
    {
        return 2 * (length + width) * height;
    }

    double getCeilArea() const
    {
        if (kleyitPotolok)
        {
            return length * width;
        }
        return 0;
    }

    double getTotalArea() const
    {
        return getWallArea() + getCeilArea();
    }
};

class Kvartira
{
public:
    Komnata* rooms;
    int count;

    Kvartira(int c)
    {
        count = c;
        rooms = new Komnata[c];
    }

    ~Kvartira()
    {
        delete[] rooms;
    }

    double getAllArea() const
    {
        double total = 0;
        for (int i = 0; i < count; i++)
        {
            total += rooms[i].getTotalArea();
        }
        return total;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int nRooms;
    cin >> nRooms;

    Kvartira kvartira(nRooms);

    for (int i = 0; i < nRooms; i++)
    {
        char name[20];
        double dl, w, h;
        int potolok;
        cin >> name >> dl >> w >> h >> potolok;
        kvartira.rooms[i] = Komnata(name, dl, w, h, potolok);
    }

    char rName[20];
    double rw, rl, price;
    cin >> rName >> rw >> rl >> price;

    RulonOboev rulon(rName, rw, rl, price);

    double totalArea = kvartira.getAllArea();
    double areaPerRulon = rulon.getArea();
    int needed = (int)ceil(totalArea / areaPerRulon);

    cout << totalArea << "\n";
    cout << areaPerRulon << "\n";
    cout << needed << "\n";
    cout << needed * rulon.price << "\n";
}
