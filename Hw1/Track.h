#pragma once
#include "Transport.h"
class Track : public Transport
{
	int wheels;
	double lifting_capacity;
	double mileage;
public:
	Track();
	Track(string m, string c, double w, double s, int wh, double lc, double mi);
	void Input();
	void Print() const;
	void Drive() const;
};

