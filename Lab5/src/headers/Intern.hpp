#pragma once
#include "Person.hpp"

class Intern : public Person
{
    public:
    Intern();
    int GetId();
    int SetId(int id);
    std::string Printify() override;

    private:
    int m_employeeId;
};