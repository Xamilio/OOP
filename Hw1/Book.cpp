#include "Book.h"
Book::Book()
{
    strcpy(title, "");
    strcpy(author, "");
    strcpy(genre, "");
    isTaken = false;
}
Book::Book(const char* t, const char* a, const char* g)
{
    strncpy(title, t, sizeof(title));
    title[sizeof(title) - 1] = '\0';
    strncpy(author, a, sizeof(author));
    author[sizeof(author) - 1] = '\0';
    strncpy(genre, g, sizeof(genre));
    genre[sizeof(genre) - 1] = '\0';
    isTaken = false;
}
Book::Book(const Book& other)
{
    strcpy(title, other.title);
    strcpy(author, other.author);
    strcpy(genre, other.genre);
    isTaken = other.isTaken;
}
Book::Book(Book&& other)
{
    strcpy(title, other.title);
    strcpy(author, other.author);
    strcpy(genre, other.genre);
    isTaken = other.isTaken;

    strcpy(other.title, "");
    strcpy(other.author, "");
    strcpy(other.genre, "");
    other.isTaken = false;
}
Book::~Book() 
{

}

void Book::print() const 
{
    cout << "Book: " << title << " (" << author << ", " << genre << ")";
    if (isTaken) cout << " [Taken]";
    else cout << " [Available]";
    cout << "\n";
}
void Book::take() 
{ 
    isTaken = true;
}
void Book::giveBack() 
{ 
    isTaken = false;
}
bool Book::available() const
{
    return !isTaken;
}
