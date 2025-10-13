#pragma once
#include "Transport.h"
class Ship : public Transport
{
	int screw;
	int cabin;
public:
	Ship();
	Ship(string m, string c, double w, double s, int sc, int cab);
	void Input();
	void Print() const;
	void Drive() const;
};

