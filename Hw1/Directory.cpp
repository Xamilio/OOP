#include "Directory.h"
#include <iostream>
#include <limits>

Directory::Directory(const string& filename) : filename(filename) {}

void Directory::addClient() 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Client c;
    cout << "\n=== Добавление новой записи ===\n";
    c.input();
    fstream file(filename, ios::in | ios::out | ios::app);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла для записи.\n";
        return;
    }
    file << c.toFileString() << "\n";
    file.close();
    cout << "Запись успешно добавлена!\n";
}
void Directory::showAll()
{
    fstream file(filename, ios::in);
    if (!file.is_open()) 
    {
        cout << "Файл не найден или пуст.\n";
        return;
    }
    string line;
    bool empty = true;
    cout << "\n=== Все записи ===\n";
    while (getline(file, line)) 
    {
        if (!line.empty())
        {
            empty = false;
            Client c = Client::fromFileString(line);
            c.print();
        }
    }

    if (empty)
        cout << "Справочник пуст.\n";

    file.close();
}

