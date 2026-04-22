#include "PresenceList.hpp"
#include "Person.hpp"

PresenceList::PresenceList(int len) : _capacity{len}, _presentCount{0}
{
    _people = new Person*[len];
    _present = new bool[len];
}

PresenceList::~PresenceList()
{
    delete[] _people;
    delete[] _present;
}

// Kody błędów:
// -1: nie można dodać - max liczba osób osiągnięta
// -2: ta sama osoba już jest na liście
int PresenceList::Add(Person *osoba)
{
    if(_presentCount >= _capacity)
        return -1;
    
    if(findIdx(osoba) != -1)
        return -2;
    
    _people[_presentCount] = osoba;
    _present[_presentCount] = false;
    _presentCount++;

    return 0;
}

// Kody błędów:
// -1: na liście nie ma tej osoby lub nie ma żadnych osób
int PresenceList::Remove(Person *person)
{
    int idx = findIdx(person);
    if(idx == -1)
        return -1;
    
    // usunięcie przez podmianę
    _people[idx]  =  _people[_presentCount-1];
    _present[idx] = _present[_presentCount-1];
    _presentCount--;
    return 0;
}

// Kody błędów:
// -1: na liście nie ma takiej osoby
int PresenceList::SetPresent(Person *osoba, bool obecna)
{
    int idx = findIdx(osoba);
    if(idx == -1)
        return -1;

    _present[idx] = obecna;
    return 0;
}

// Kody:
// -1 = BRAK OSOBY NA LISCIE
// 0 = NIEOBECNA
// 1 = OBECNA
int PresenceList::IsPresent(Person *osoba)
{
    int idx = findIdx(osoba);
    if(idx == -1) return -1;
    return (_present[idx] ? 1 : 0);
}

int PresenceList::findIdx(Person *osoba)
{
    for(int i = 0; i < _presentCount; i++)
    {
        if(_people[i]->GetIndex() == osoba->GetIndex())
            return i;
    }

    return -1;
}