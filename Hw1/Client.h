#pragma once
#include <iostream>
#include <string>
using namespace std;

class Client {
private:
    string name;
    string owner;
    string phone;
    string address;
    string activity;

public:
    Client();
    Client(string name, string owner, string phone, string address, string activity);
    void input();
    void print() const;

    string getName() const;
    string getOwner() const;
    string getPhone() const;
    string getAddress() const;
    string getActivity() const;
    string toFileString() const;
    static Client fromFileString(const string& line);
};