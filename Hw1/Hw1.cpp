#include <iostream>
#include <memory>
using namespace std;

class DeliveryStrategy {
public:
    virtual double calculateCost(double distance, double weight) = 0;
    virtual ~DeliveryStrategy() {}
};

class CourierDelivery : public DeliveryStrategy {
public:
    double calculateCost(double distance, double weight) override {
        return 50 + 10 * distance;
    }
};

class PickupDelivery : public DeliveryStrategy {
public:
    double calculateCost(double distance, double weight) override {
        return 0;
    }
};

class PostDelivery : public DeliveryStrategy {
public:
    double calculateCost(double distance, double weight) override {
        return 25 + 5 * weight;
    }
};

class Order {
private:
    unique_ptr<DeliveryStrategy> delivery;
    double distance;
    double weight;
public:
    Order(double dist, double w, DeliveryStrategy* del) 
        : distance(dist), weight(w), delivery(del) {}

    void setDelivery(DeliveryStrategy* del) {
        delivery.reset(del);
    }

    double getDeliveryCost() {
        return delivery->calculateCost(distance, weight);
    }
};

int main() {
    Order order1(10, 2, new CourierDelivery());
    cout << order1.getDeliveryCost() << endl;

    order1.setDelivery(new PickupDelivery());
    cout << order1.getDeliveryCost() << endl;

    order1.setDelivery(new PostDelivery());
    cout << order1.getDeliveryCost() << endl;

    return 0;
}
