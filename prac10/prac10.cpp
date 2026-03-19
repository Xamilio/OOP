#include <iostream>
#include <string>
using namespace std;

class IMediator
{
public:
    virtual void notify(string event) = 0;
};

class Light
{
private:
    bool state;

public:
    Light()
    {
        state = false;
    }

    void turnOn()
    {
        state = true;
        cout << "Light is ON" << endl;
    }

    void turnOff()
    {
        state = false;
        cout << "Light is OFF" << endl;
    }

    bool isOn()
    {
        return state;
    }
};

class Switch
{
private:
    IMediator* mediator;

public:
    Switch(IMediator* mediator)
    {
        this->mediator = mediator;
    }

    void press()
    {
        mediator->notify("switch_pressed");
    }
};

class RoomMediator : public IMediator
{
private:
    Light* light;

public:
    RoomMediator(Light* light)
    {
        this->light = light;
    }

    void notify(string event) override
    {
        if (event == "switch_pressed")
        {
            if (light->isOn())
            {
                light->turnOff();
            }
            else
            {
                light->turnOn();
            }
        }
    }
};

int main()
{
    Light light;
    RoomMediator mediator(&light);
    Switch sw(&mediator);

    string command;

    while (true)
    {
        cout << "Enter command (press / exit): ";
        cin >> command;

        if (command == "press")
        {
            sw.press();
        }
        else if (command == "exit")
        {
            break;
        }
    }

    return 0;
}
