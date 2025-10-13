#include "Ship.h"
#include <iostream>
using namespace std;
Ship::Ship()
{
	screw = 0;
	cabin = 0;
}

Ship::Ship(string m, string c, double w, double s, int sc, int cab) : Transport(m, c, w, s)
{
	screw = sc;
	cabin = cab;
}

void Ship::Input()
{
	Transport::Input();
	cout << "Enter number of screws: ";
	cin >> screw;
	cout << "Enter number of cabins: ";
	cin >> cabin;
}

void Ship::Print() const
{
	Transport::Print();
	cout << "Number of screws: " << screw << endl;
	cout << "Number of cabins: " << cabin << endl;
}

void Ship::Drive() const
{
	cout << "The ship is sailing" << endl;
}
