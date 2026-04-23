#include <iostream>
#include "Person.hpp"
#include "PresenceList.hpp"
#include "UI.hpp"

const int PERSON_COUNT = 10;
const int LIST_COUNT = 2;

int main()
{
    Person* people[PERSON_COUNT] = { nullptr };
    
    PresenceList* presence[LIST_COUNT];
    for (int i = 0; i < LIST_COUNT; ++i)
        presence[i] = new PresenceList(PERSON_COUNT);

    UI* ui = new UI(people, presence, LIST_COUNT);
    ui->Loop();
}