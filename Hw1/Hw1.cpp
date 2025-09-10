#include <iostream>
using namespace std;

class Lift 
{
    int minFloor;
    int maxFloor;
    int currentFloor;
    bool isOn;
public:
    Lift(int minF = 1, int maxF = 9) : minFloor(minF), maxFloor(maxF), currentFloor(minF), isOn(false) 
    {
         
    }

    void TurnOn()
    {
        isOn = true;
        cout << "Лифт включен.\n";
    }
    void TurnOff()
    {
        isOn = false;
        cout << "Лифт выключен.\n";
    }
    bool IsOn() const 
    {
        return isOn;
    }
    int GetCurrentFloor() const
    {
        return currentFloor;
    }
    void SetRange(int minF, int maxF)
    {
        if (minF < maxF) 
        {
            minFloor = minF;
            maxFloor = maxF;
            currentFloor = minF;
        }
    }
    void Call(int floor) 
    {
        if (!isOn) 
        {
            cout << "Лифт не работает!\n";
            return;
        }
        if (floor < minFloor || floor > maxFloor)
        {
            cout << "Ошибка: такого этажа нет!\n";
            return;
        }
        cout << "Лифт движется с " << currentFloor << " этажа на " << floor << " этаж...\n";
        currentFloor = floor;
        cout << "Лифт прибыл на этаж " << currentFloor << ".\n";
    }
    void Print() 
    {
        cout << "---- Лифт ----\n";
        cout << "Диапазон этажей: " << minFloor << " - " << maxFloor << endl;
        cout << "Текущий этаж: " << currentFloor << endl;
        cout << "Состояние: " << (isOn ? "Работает" : "Выключен") << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "ru");
    Lift lift(1, 5);

    int choice;
    do
    {
        cout << "\nМеню:\n";
        cout << "1. Включить лифт\n";
        cout << "2. Выключить лифт\n";
        cout << "3. Вызвать лифт на этаж\n";
        cout << "4. Показать состояние\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            lift.TurnOn();
            break;
        case 2:
            lift.TurnOff();
            break;
        case 3: {
            int floor;
            cout << "Введите этаж: ";
            cin >> floor;
            lift.Call(floor);
            break;
        }
        case 4:
            lift.Print();
            break;
        case 0:
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}
