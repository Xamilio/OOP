#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() : bookCount(0), readerCount(0)
{

}

void Library::addBook(const Book& b) {
    if (bookCount < 100)
    {
        books[bookCount] = b;
        bookCount++;
    }
}

void Library::addReader(const Reader& r)
{
    if (readerCount < 100) {
        readers[readerCount] = r;
        readerCount++;
    }
}

void Library::showBooks() const
{
    cout << "\nBooks in library:\n";
    for (int i = 0; i < bookCount; i++)
    {
        books[i].print();
    }
}

void Library::showReaders() const
{
    cout << "\nReaders in library:\n";
    for (int i = 0; i < readerCount; i++)
    {
        readers[i].print();
    }
}
