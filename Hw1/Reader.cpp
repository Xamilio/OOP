#include "Reader.h"

Reader::Reader()
{
    strcpy(name, "");
    id = 0;
    booksTaken = 0;
}

Reader::Reader(const char* n, int i)
{
    strncpy(name, n, sizeof(name));
    name[sizeof(name) - 1] = '\0';
    id = i;
    booksTaken = 0;
}

Reader::Reader(const Reader& other)
{
    strcpy(name, other.name);
    id = other.id;
    booksTaken = other.booksTaken;
}

Reader::Reader(Reader&& other)
{
    strcpy(name, other.name);
    id = other.id;
    booksTaken = other.booksTaken;

    strcpy(other.name, "");
    other.id = 0;
    other.booksTaken = 0;
}

Reader::~Reader()
{

}

void Reader::print() const 
{
    cout << "Reader: " << name << " (ID: " << id << "), Books: " << booksTaken << "\n";
}

void Reader::takeBook() 
{
    booksTaken++;
}
void Reader::returnBook() 
{
    if (booksTaken > 0) booksTaken--;
}
