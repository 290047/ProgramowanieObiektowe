#pragma once
#include "Person.hpp"
#include "PresenceList.hpp"

class UI
{
public:
    UI(Person** people, PresenceList** presenceLists, int listCount);
    void Loop();

private:
    Person** m_people;
    PresenceList** m_presenceLists;

    int m_count;
    int m_listCount;
    int m_selectedList;

    void printMenu();
    void displayPeople();

    void addStudent();
    void addIntern();

    void removePerson(int idx);

    void changeName(int idx);
    void changeSurname(int idx);

    void selectList();
    PresenceList* currentList();
};