#include "Intern.hpp"

Intern::Intern() :
    Person(),
    m_employeeId(0)
{ }

void Intern::Print(char endChar)
{
    std::cout << "Stażysta " << m_name << ' ' << m_surname << " nr pracownika: " << m_employeeId << '\n';
}

int Intern::GetId() { return m_employeeId; };

// Kody błędów:
// -1: Id jest ujemne
int Intern::SetId(int id)
{
    if(id < 0)
        return -1;
        
    m_employeeId = id;
    return 0;
}