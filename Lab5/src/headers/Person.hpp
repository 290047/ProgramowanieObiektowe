#pragma once
#include <iostream>
#include "IPrintable.hpp"

class Person : public IPrintable
{
    public:
    Person();
    virtual std::string Printify();
    std::string GetName();
    std::string GetSurname();
    int SetName(std::string name);
    int SetSurname(std::string surname);

    protected:
    std::string m_name;
    std::string m_surname;
};