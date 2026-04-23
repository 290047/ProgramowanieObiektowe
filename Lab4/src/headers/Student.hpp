#pragma once
#include "Person.hpp"

class Student : public Person
{
    public:
    Student();
    int GetIndex();
    int SetIndex(int index);
    void Print(char endChar = ' ');

    private:
    int m_index;
};