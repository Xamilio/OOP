#include "Client.h"
#include <sstream>

Client::Client() {}

Client::Client(string name, string owner, string phone, string address, string activity) : name(name), owner(owner), phone(phone), address(address), activity(activity) {
}

void Client::input()
{
    cout << "Название фирмы: ";
    getline(cin, name);
    cout << "Владелец: ";
    getline(cin, owner);
    cout << "Телефон: ";
    getline(cin, phone);
    cout << "Адрес: ";
    getline(cin, address);
    cout << "Род деятельности: ";
    getline(cin, activity);
}

void Client::print() const 
{
    cout << "Фирма: " << name << "\n"
        << "Владелец: " << owner << "\n"
        << "Телефон: " << phone << "\n"
        << "Адрес: " << address << "\n"
        << "Род деятельности: " << activity << "\n"
        << "-----------------------------\n";
}

string Client::getName() const 
{ 
    return name;
}
string Client::getOwner() const 
{ 
    return owner; 
}
string Client::getPhone() const 
{
    return phone;
}
string Client::getAddress() const
{
    return address;
}
string Client::getActivity() const 
{ 
    return activity;
}

string Client::toFileString() const
{
    return name + ";" + owner + ";" + phone + ";" + address + ";" + activity;
}

Client Client::fromFileString(const string& line)
{
    stringstream ss(line);
    string n, o, p, a, act;
    getline(ss, n, ';');
    getline(ss, o, ';');
    getline(ss, p, ';');
    getline(ss, a, ';');
    getline(ss, act, ';');
    return Client(n, o, p, a, act);
}
