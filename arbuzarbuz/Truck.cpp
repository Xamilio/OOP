#include "Truck.h"

using namespace std;

Truck::Truck(double load, double max_load, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol), load(load), max_load(max_load) {}

double Truck::getCurrentLoad() const {
    return load;
}

double Truck::getMaxLoad() const {
    return max_load;
}

void Truck::arrive() {
    Base::goods_on_base += load;
    Base::vehicles_on_base++;
    Base::people_on_base++; // водитель
    cout << "Truck arrived. Goods on base: " << Base::goods_on_base << " tons\n";
}

bool Truck::leave() {
    if (Base::people_on_base < 1 || Base::petrol_on_base < (tank_volume - petrol_amount)) {
        cout << "Not enough resources to leave\n";
        return false;
    }
    refuel();
    double goods_to_take = min(Base::goods_on_base, max_load);
    Base::goods_on_base -= goods_to_take;
    Base::vehicles_on_base--;
    Base::people_on_base--;
    cout << "Truck left with " << goods_to_take << " tons of goods\n";
    return true;
}