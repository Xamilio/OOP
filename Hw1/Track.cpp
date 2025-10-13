#include "Track.h"
#include <iostream>
using namespace std;

Track::Track()
{
	wheels = 0;
	lifting_capacity = 0;
	mileage = 0;
}
Track::Track(string m, string c, double w, double s, int wh, double lc, double mi) : Transport(m, c, w, s)
{
	wheels = wh;
	lifting_capacity = lc;
	mileage = mi;
}
void Track::Input()
{
	Transport::Input();
	cout << "Enter number of wheels: ";
	cin >> wheels;
	cout << "Enter lifting capacity: ";
	cin >> lifting_capacity;
	cout << "Enter mileage: ";
	cin >> mileage;
}
void Track::Print() const
{
	Transport::Print();
	cout << "Number of wheels: " << wheels << endl;
	cout << "Lifting capacity: " << lifting_capacity << endl;
	cout << "Mileage: " << mileage << endl;
}
void Track::Drive() const
{
	cout << "The track is driving" << endl;
}
