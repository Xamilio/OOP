#pragma once
#include <iostream>
#include <string>
#include "Base.h"

using namespace std;

class Vehicle {
protected:
    string driver;
    double petrol_amount;
    double tank_volume;

public:
    Vehicle(double petrol_amount, double tank_volume);
    virtual ~Vehicle() = default;

    virtual void arrive() = 0;
    virtual bool leave() = 0;

    double getPetrolAmount() const;
    double getTankVolume() const;
    void refuel();
};