#pragma once
#include <iostream>

class IPrintable
{
    public:
    virtual std::string Printify() = 0;
};