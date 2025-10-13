#pragma once
#include "Transport.h"
class Car : public Transport
{
	int wheels;
	int places;
	double lifting_capacity;
public:
	Car();
	Car(string m, string c, double w, double s, int wh, int pl, double lc);
	void Input();
	void Print() const;
	void Drive() const;
};

