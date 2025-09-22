#pragma once
#include "Book.h"
#include "Reader.h"

class Library 
{
    Book books[100];
    Reader readers[100];
    int bookCount;
    int readerCount;
public:
    Library();
    void addBook(const Book& b);
    void addReader(const Reader& r);
    void showBooks() const;
    void showReaders() const;
};
