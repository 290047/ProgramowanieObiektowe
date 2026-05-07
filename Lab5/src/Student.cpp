#include "Student.hpp"

Student::Student() :
    Person(),
    m_index(0)
{ }

std::string Student::Printify()
{
    return "Student " + m_name + ' ' + m_surname + " nr indeksu: " + std::to_string(m_index);
}

int Student::GetIndex() { return m_index; };

// Kody błędów:
// -1: Indeks jest ujemny
int Student::SetIndex(int index)
{
    if(index < 0)
        return -1;
        
    m_index = index;
    return 0;
}