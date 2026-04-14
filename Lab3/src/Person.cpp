#include "Person.hpp"

Person::Person() :
    _index(),
    _name(),
    _surname()
{

}

std::string Person::GetName()    { return _name;    };
std::string Person::GetSurname() { return _surname; };
int Person::GetIndex()           { return _index;   };

// Kody błędów:
// -1: Imie ma <2 znaki
int Person::SetName(std::string name)
{
    if(name.size() < 2)
        return -1;

    _name = name;
    return 0;
}

// Kody błędów:
// -1: Nazwisko ma <2 znaki
int Person::SetSurname(std::string surname)
{
    if(surname.size() < 2)
        return -1;
        
    _surname = surname;
    return 0;
}

// Kody błędów:
// -1: Indeks jest ujemny
int Person::SetIndex(int index)
{
    if(index < 0)
        return -1;
        
    _index = index;
    return 0;
}