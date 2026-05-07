#include "PartTimeStudent.hpp"

PartTimeStudent::PartTimeStudent() :
    Student()
{ }

std::string PartTimeStudent::Printify()
{
    return "Student (Zaoczny) " + m_name + ' ' + m_surname + " nr indeksu: " + std::to_string(m_index);
}