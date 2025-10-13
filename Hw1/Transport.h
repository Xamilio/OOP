#pragma once
#include <string>
using namespace std;
class Transport
{
	string model;
	string color;
	double weight;
	double speed;
public:
	Transport();
	Transport(string m, string c, double w, double s);
	void Input();
	void Print() const;
	double GetMaxSpeed() const;
	void Drive() const;
};

