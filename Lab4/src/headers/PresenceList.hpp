#pragma once
#include "Person.hpp"
#include <iostream>

class PresenceList
{
    public:
    PresenceList(int len);
    ~PresenceList();
    int Add(Person *person);
    int Remove(Person *person);
    int SetPresent(Person *person, bool obecna);
    int IsPresent(Person *person);

    private:
    int m_capacity;
    int m_presentCount;
    bool *m_present;
    Person **m_people;
};