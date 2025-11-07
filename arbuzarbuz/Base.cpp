#include "Base.h"

using namespace std;

int Base::people_on_base = 0;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 0.0;
double Base::goods_on_base = 0.0;

void Base::Init(int people, int vehicles, double petrol, double goods) {
    people_on_base = people;
    vehicles_on_base = vehicles;
    petrol_on_base = petrol;
    goods_on_base = goods;
}

void Base::PrintStatus() {
    cout << "People on base: " << people_on_base << "\n";
    cout << "Vehicles on base: " << vehicles_on_base << "\n";
    cout << "Petrol on base: " << petrol_on_base << " liters\n";
    cout << "Goods on base: " << goods_on_base << " tons\n";
}