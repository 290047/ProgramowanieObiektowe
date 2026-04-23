#pragma once
#include <iostream>

class Person
{
    public:
    Person();
    void Print(char endChar = ' ');
    std::string GetName();
    std::string GetSurname();
    int SetName(std::string name);
    int SetSurname(std::string surname);

    protected:
    std::string m_name;
    std::string m_surname;
};