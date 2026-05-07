#pragma once
#include "Student.hpp"

class PartTimeStudent : public Student
{
    public:
    PartTimeStudent();
    std::string Printify() override;
};