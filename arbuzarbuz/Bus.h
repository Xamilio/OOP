#pragma once
#include "Vehicle.h"

class Bus : public Vehicle {
private:
    int people;
    int max_people;

public:
    Bus(int people, int max_people, double petrol, double max_petrol);

    int getPeopleCount() const;
    int getMaxPeople() const;

    void arrive() override;
    bool leave() override;
};