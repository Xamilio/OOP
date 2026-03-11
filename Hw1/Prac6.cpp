#include <iostream>
using namespace std;


class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};


class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivery by truck (road transport)" << endl;
    }
};


class Ship : public Transport {
public:
    void deliver() override {
        cout << "Delivery by ship (sea transport)" << endl;
    }
};

class Logistics {
public:
    virtual Transport* createTransport() = 0;

    void planDelivery() {
        Transport* t = createTransport();
        t->deliver();
        delete t;
    }

    virtual ~Logistics() {}
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

int main() {
    Logistics* logistics;

    int choice;
    cout << "1 - Road delivery\n2 - Sea delivery\nChoose: ";
    cin >> choice;

    if (choice == 1)
        logistics = new RoadLogistics();
    else
        logistics = new SeaLogistics();

    logistics->planDelivery();

    delete logistics;
}
