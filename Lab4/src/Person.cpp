#include "Person.hpp"

Person::Person() :
    m_name(),
    m_surname()
{ }

void Person::Print(char endChar)
{
    std::cout << m_name << " " << m_surname << endChar;
}

std::string Person::GetName()    { return m_name;    };
std::string Person::GetSurname() { return m_surname; };

// Kody błędów:
// -1: Imie ma <2 znaki
int Person::SetName(std::string name)
{
    if(name.size() < 2)
        return -1;

    m_name = name;
    return 0;
}

// Kody błędów:
// -1: Nazwisko ma <2 znaki
int Person::SetSurname(std::string surname)
{
    if(surname.size() < 2)
        return -1;
        
    m_surname = surname;
    return 0;
}