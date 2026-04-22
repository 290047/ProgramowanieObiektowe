#pragma once
#include "Person.hpp"
#include "PresenceList.hpp"

class UI
{
public:
    UI(Person** people, PresenceList** presenceLists, int listCount);
    void Loop();

private:
    Person** _people;
    PresenceList** _presenceLists;

    int _count;
    int _listCount;
    int _selectedList;

    void printMenu();
    void displayPeople();

    void addPerson(Person* nPerson);
    int removePerson(int indeks);
    int changeName(int index, std::string nName);
    int changeSurname(int index, std::string nSurname);
    int findIdx(int index);

    void selectList();
    PresenceList* currentList();
};