#include "PresenceList.hpp"
#include "Person.hpp"

PresenceList::PresenceList(int len) :
    m_capacity{len},
    m_presentCount{0}
{
    m_people = new Person*[len];
    m_present = new bool[len];
}

PresenceList::~PresenceList()
{
    delete[] m_people;
    delete[] m_present;
}

// Kody błędów:
// -1: nie można dodać - max liczba osób osiągnięta
// -2: ta sama osoba już jest na liście
int PresenceList::Add(Person *person)
{
    if(m_presentCount >= m_capacity)
        return -1;

    for(int i = 0; i < m_presentCount; i++)
        if(m_people[i] == person)
            return -2;

    m_people[m_presentCount] = person;
    m_present[m_presentCount] = false;
    m_presentCount++;

    return 0;
}

// Kody błędów:
// -1: na liście nie ma tej osoby lub nie ma żadnych osób
int PresenceList::Remove(Person *person)
{
    for(int i = 0; i < m_presentCount; i++)
    {
        if(m_people[i] == person)
        {
            // usunięcie przez podmianę
            m_people[i] = m_people[m_presentCount-1];
            m_present[i] = m_present[m_presentCount-1];
            m_presentCount--;
            return 0;
        }
    }
    return -1;
}

// Kody błędów:
// -1: na liście nie ma takiej osoby
int PresenceList::SetPresent(Person *person, bool present)
{
    for(int i = 0; i < m_presentCount; i++)
    {
        if(m_people[i] == person)
        {
            m_present[i] = present;
            return 0;
        }
    }

    return -1;
}

// Kody:
// -1 = BRAK OSOBY NA LISCIE
// 0 = NIEOBECNA
// 1 = OBECNA
int PresenceList::IsPresent(Person *person)
{
    for(int i = 0; i < m_presentCount; i++)
        if(person == m_people[i])
            return m_present[i];

    return -1;
}