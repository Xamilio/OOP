#pragma once
#include "Client.h"
#include <string>
using namespace std;

class Directory 
{
private:
    string filename;
public:
    Directory(const string& filename);

    void addClient();
    void showAll() const;
    void searchByName(const string& name) const;
    void searchByOwner(const string& owner) const;
    void searchByPhone(const string& phone) const;
    void searchByActivity(const string& activity) const;
};
