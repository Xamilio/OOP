#include "Airplane.h"
#include<iostream>
using namespace std;
Airplane::Airplane()
{
	wingspan = 0.0;
	flight_hours = 0;
}

Airplane::Airplane(string m, string c, double w, double s, double ws, int fh) : Transport(m, c, w, s)
{
	wingspan = ws;
	flight_hours = fh;
}

void Airplane::Input()
{
	Transport::Input();
	cout << "Enter wingspan: ";
	cin >> wingspan;
	cout << "Enter flight hours: ";
	cin >> flight_hours;
}

void Airplane::Print() const
{
	Transport::Print();
	cout << "Wingspan: " << wingspan << endl;
	cout << "Flight hours: " << flight_hours << endl;
}

void Airplane::Drive() const
{
	cout << "Airplane is flying.....\n";
}
