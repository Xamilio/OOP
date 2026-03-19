#include <iostream>

using namespace std;

class Observer {
public:
    virtual void update(float temperature) = 0;
    virtual ~Observer() {}
};

class Subject {
protected:
    Observer* observers[10];
    int count = 0;

public:
    void attach(Observer* obs) {
        if (count < 10) {
            observers[count++] = obs;
        }
    }

    void detach(Observer* obs) {
        for (int i = 0; i < count; i++) {
            if (observers[i] == obs) {
                for (int j = i; j < count - 1; j++) {
                    observers[j] = observers[j + 1];
                }
                count--;
                break;
            }
        }
    }

    void notify(float temperature) {
        for (int i = 0; i < count; i++) {
            observers[i]->update(temperature);
        }
    }
};

class TemperatureSensor : public Subject {
private:
    float temperature;

public:
    void setTemperature(float temp) {
        temperature = temp;
        notify(temperature);
    }

    float getTemperature() {
        return temperature;
    }
};

class ConsoleDisplay : public Observer {
public:
    void update(float temperature) override {
        cout << "Температура: " << temperature << endl;
    }
};

class Logger : public Observer {
public:
    void update(float temperature) override {
        cout << "[LOG] Новая температура: " << temperature << endl;
    }
};

class Alarm : public Observer {
public:
    void update(float temperature) override {
        if (temperature >= 30) {
            cout << "!!! ВНИМАНИЕ: высокая температура !!!" << endl;
        }
    }
};

int main() {
    TemperatureSensor sensor;

    ConsoleDisplay display;
    Logger logger;
    Alarm alarm;

    sensor.attach(&display);
    sensor.attach(&logger);
    sensor.attach(&alarm);

    sensor.setTemperature(25);
    sensor.setTemperature(30);
    sensor.setTemperature(35);

    return 0;
