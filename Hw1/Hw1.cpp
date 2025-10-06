#include "Queue.h"
#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    Queue printQueue(5);
    Queue statQueue(5);

    printQueue.Add(Worker("Андрей", "Отчет"));
    printQueue.Add(Worker("Марина", "Контрольная"));
    printQueue.Add(Worker("Сергей", "Докладt"));

    while (!printQueue.isEmpty()) 
    {
        Worker w = printQueue.Extract();
        cout << "Печатается: ";
        w.PrintInfo();
        statQueue.Add(w);
    }

    cout << "\n=== Статистика печати ===" << endl;
    statQueue.ShowAll();
}
