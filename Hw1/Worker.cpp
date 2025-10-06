#include "Worker.h"

Worker::Worker() : name(""), printText("")
{

}

Worker::Worker(const string& n, const string& text) : name(n), printText(text) 
{
}

string Worker::GetName() const 
{
    return name;
}

string Worker::GetText() const 
{
    return printText;
}

void Worker::PrintInfo() const 
{
    cout << "Пользователь: " << name << " | Текст: " << printText << endl;
}
