#include "Bus.h"

using namespace std;

Bus::Bus(int people, int max_people, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol), people(people), max_people(max_people) {}

int Bus::getPeopleCount() const {
    return people;
}

int Bus::getMaxPeople() const {
    return max_people;
}

void Bus::arrive() {
    Base::people_on_base += (people + 1); // +1 за водителя
    Base::vehicles_on_base++;
    cout << "Bus arrived. People on base: " << Base::people_on_base << "\n";
}

bool Bus::leave() {
    if (Base::people_on_base < 1 || Base::petrol_on_base < (tank_volume - petrol_amount)) {
        cout << "Not enough resources to leave\n";
        return false;
    }
    refuel();
    int people_to_take = min(Base::people_on_base - 1, max_people); // оставляем водителя
    Base::people_on_base -= people_to_take + 1;
    Base::vehicles_on_base--;
    cout << "Bus left with " << people_to_take << " passengers\n";
    return true;
}