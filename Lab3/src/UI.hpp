#pragma once
#include "Person.hpp"
#include "PresenceList.hpp"

class UI
{
    public:
    UI(Person** people, PresenceList* presenceList);
    void Loop();
    
    private:
    Person **_people;
    PresenceList *_presenceList;
    int _count;
    void printMenu();
    void displayPeople();
    void addPerson(Person* nPerson);
    int removePerson(int indeks);
    int changeName(int index, std::string nName);
    int changeSurname(int index, std::string nSurname);
    int findIdx(int index);
};