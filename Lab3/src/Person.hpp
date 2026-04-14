#pragma once
#include <iostream>

class Person
{
    public:
    Person();
    std::string GetName();
    std::string GetSurname();
    int GetIndex();
    int SetName(std::string name);
    int SetSurname(std::string surname);
    int SetIndex(int index);

    private:
    int _index;
    std::string _name;
    std::string _surname;
};