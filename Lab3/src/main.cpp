#include <iostream>
#include "Person.hpp"
#include "PresenceList.hpp"
#include "UI.hpp"

const int N = 10;

int main()
{
    Person *people[N] = {nullptr};
    PresenceList *presence = new PresenceList(N);
    UI *ui = new UI(people, presence);
    ui->Loop();
}