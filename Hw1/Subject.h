#pragma once
class Subject
{
private:
    char name[30];

public:
    Subject();
    void setName(const char* n);
    const char* getName() const;
};
