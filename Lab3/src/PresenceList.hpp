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
    int _capacity;
    int _presentCount;
    bool *_present;
    Person **_people;
    int findIdx(Person *person);
};