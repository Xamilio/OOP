#include <iostream>
#include"Transport.h"
#include"Car.h"
#include"Ship.h"
#include"Track.h"
#include "Airplane.h"
using namespace std;

int main()
{
	Car car;
	Track track;
	Ship ship;
	Airplane airplane;

	cout << "Input car data:" << endl;
	car.Input();
	cout << endl;
	cout << "Input track data:" << endl;
	track.Input();
	cout << endl;
	cout << "Input ship data:" << endl;
	ship.Input();
	cout << endl;
	cout << "Input airplane data:" << endl;
	airplane.Input();
	cout << endl;
	cout << "Car data:" << endl;
	car.Print();
	cout << endl;
	cout << "Track data:" << endl;
	track.Print();
	cout << endl;
	cout << "Ship data:" << endl;
	ship.Print();
	cout << endl;
	cout << "Airplane data:" << endl;
	airplane.Print();
}
