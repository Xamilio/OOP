#include "Library.h"
int main() 
{
    Library lib;
    Book b1("War and Peace", "Leo Tolstoy", "Novel");
    Book b2("1984", "George Orwell", "Dystopia");
    Reader r1("Ivan", 1);
    Reader r2("Anna", 2);
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addReader(r1);
    lib.addReader(r2);
    lib.showBooks();
    lib.showReaders();
}
