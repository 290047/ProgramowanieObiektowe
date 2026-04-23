#pragma once
#include "Person.hpp"

class Intern : public Person
{
    public:
    Intern();
    int GetId();
    int SetId(int id);
    void Print(char endChar = ' ');

    private:
    int m_employeeId;
};