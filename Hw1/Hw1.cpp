#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* full_name;
    char* birth_date;
    char* phone;
    char* city;
    char* country;
    char* university;
    char* university_city;
    char* university_country;
    char* group_number;

public:
    Student()
    {
        full_name = birth_date = phone = city = country = university = university_city = university_country = group_number = 0;
    }

    ~Student()
    {
        delete[] full_name;
        delete[] birth_date;
        delete[] phone;
        delete[] city;
        delete[] country;
        delete[] university;
        delete[] university_city;
        delete[] university_country;
        delete[] group_number;
    }

    void Init()
    {
        char buffer[100];

        cout << "Enter full name: ";
        cin.getline(buffer, 100);
        full_name = new char[strlen(buffer) + 1];
        strcpy_s(full_name, strlen(buffer) + 1, buffer);

        cout << "Enter birth date: ";
        cin.getline(buffer, 100);
        birth_date = new char[strlen(buffer) + 1];
        strcpy_s(birth_date, strlen(buffer) + 1, buffer);

        cout << "Enter phone: ";
        cin.getline(buffer, 100);
        phone = new char[strlen(buffer) + 1];
        strcpy_s(phone, strlen(buffer) + 1, buffer);

        cout << "Enter city: ";
        cin.getline(buffer, 100);
        city = new char[strlen(buffer) + 1];
        strcpy_s(city, strlen(buffer) + 1, buffer);

        cout << "Enter country: ";
        cin.getline(buffer, 100);
        country = new char[strlen(buffer) + 1];
        strcpy_s(country, strlen(buffer) + 1, buffer);

        cout << "Enter university: ";
        cin.getline(buffer, 100);
        university = new char[strlen(buffer) + 1];
        strcpy_s(university, strlen(buffer) + 1, buffer);

        cout << "Enter university city: ";
        cin.getline(buffer, 100);
        university_city = new char[strlen(buffer) + 1];
        strcpy_s(university_city, strlen(buffer) + 1, buffer);

        cout << "Enter university country: ";
        cin.getline(buffer, 100);
        university_country = new char[strlen(buffer) + 1];
        strcpy_s(university_country, strlen(buffer) + 1, buffer);

        cout << "Enter group number: ";
        cin.getline(buffer, 100);
        group_number = new char[strlen(buffer) + 1];
        strcpy_s(group_number, strlen(buffer) + 1, buffer);
    }

    void print()
    {
        cout << "Student info:\n";
        cout << "Full name: " << full_name << endl;
        cout << "Birth date: " << birth_date << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University: " << university << endl;
        cout << "University city: " << university_city << endl;
        cout << "University country: " << university_country << endl;
        cout << "Group number: " << group_number << endl;
    }

    char* GetFullName()
    {
        return full_name;
    }

    void SetFullName(const char* fn)
    {
        delete[] full_name;
        full_name = new char[strlen(fn) + 1];
        strcpy_s(full_name, strlen(fn) + 1, fn);
    }

    char* GetGroupNumber()
    {
        return group_number;
    }

    void SetGroupNumber(const char* gn)
    {
        delete[] group_number;
        group_number = new char[strlen(gn) + 1];
        strcpy_s(group_number, strlen(gn) + 1, gn);
    }
};

int main()
{
    Student s;
    s.Init();
    s.print();

    cout << "Full name: " << s.GetFullName() << endl;
    s.SetFullName("Artem Lol");
    cout << "Full name: " << s.GetFullName() << endl;

    cout << "Group number: " << s.GetGroupNumber() << endl;
    s.SetGroupNumber("Kn241-P");
    cout << "Group number: " << s.GetGroupNumber() << endl;
}