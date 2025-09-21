#pragma once
class Subject
{
private:
    char* name;
public:
    Subject();
    ~Subject();
     Subject(const Subject& other);
    void setName(const char* n);
    const char* getName();
};


