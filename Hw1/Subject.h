#pragma once
class Subject
{
private:
    char* name;
public:
    Subject();
    ~Subject();
    void setName(const char* n);
    const char* getName();
};

