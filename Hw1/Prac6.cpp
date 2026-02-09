#include <iostream>
#include"Transport.h"
#include"Car.h"
#include"Ship.h"
#include"Track.h"
#include "Airplane.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the type of transport (1 - car, 2 - track, 3 - ship, 4 - airplane): ";
	cin >> n;
	switch n
	{
		case 1:
		{
			Transport car;
			car.Input();
			car.Output();
		}
		case 2:
		{
			Transport Track;
			track.Input();
			track.Output();
		}
		case 3:
		{
			Transport Ship;
			ship.Input();
			ship.Output();
		}
		case 4:
		{
			Transport Airplane;
			airplane.Input();
			airplane.Output();
		}
		default:
			cout << "Error";
	}

}
