#pragma once
#include "Base.h"
#include "Bus.h"
#include "Truck.h"

class Game {
public:
    void drawBase();
    void showMenu();

private:
    Bus bus{ 10, 20, 50, 100 };
    Truck truck{ 8, 15, 30, 100 };

    void busArrive();
    void truckArrive();
    void busLeave();
    void truckLeave();
    void waitForEnter();
};