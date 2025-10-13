#include<iostream>
#include "Transport.h"
using namespace std;
Transport::Transport()
{
	weight = 0.0;
	speed = 0.0;
}

Transport::Transport(string m, string c, double w, double s)
{
	model = m;
	color = c;
	weight = w;
	speed = s;
}

void Transport::Input()
{
	cout << "Enter model: ";
	cin >> model;
	cout << "Enter color: ";
	cin >> color;
	cout << "Enter weight: ";
	cin >> weight;
	cout << "Enter speed: ";
	cin >> speed;
}

void Transport::Print() const
{
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << "Weight: " << weight << endl;
	cout << "Speed: " << speed << endl;
}

double Transport::GetMaxSpeed() const
{
	return speed;
}

void Transport::Drive() const
{
	cout << "Transport is moving.....\n";
}
