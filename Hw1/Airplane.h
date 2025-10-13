#pragma once
#include "Transport.h"
class Airplane : public Transport
{
	double wingspan;
	int flight_hours;
public:
	Airplane();
	Airplane(string m, string c, double w, double s, double ws, int fh);
	void Input();
	void Print() const;
	void Drive() const;
	
};

