#include "Car.h"
#include <iostream>
using namespace std;

Car::Car()
{
	wheels = 0;
	places = 0;
	lifting_capacity = 0;
}
Car::Car(string m, string c, double w, double s, int wh, int pl, double lc) : Transport(m, c, w, s)
{
	wheels = wh;
	places = pl;
	lifting_capacity = lc;
}
void Car::Input()
{
	Transport::Input();
	cout << "Enter number of wheels: ";
	cin >> wheels;
	cout << "Enter number of places: ";
	cin >> places;
	cout << "Enter lifting capacity: ";
	cin >> lifting_capacity;
}
void Car::Print() const
{
	Transport::Print();
	cout << "Number of wheels: " << wheels << endl;
	cout << "Number of places: " << places << endl;
	cout << "Lifting capacity: " << lifting_capacity << endl;
}
void Car::Drive() const
{
	cout << "The car is driving" << endl;
}
