#pragma once
#include "Person.hpp"

class Student : public Person
{
    public:
    Student();
    int GetIndex();
    int SetIndex(int index);
    virtual std::string Printify() override;

    protected:
    int m_index;
};