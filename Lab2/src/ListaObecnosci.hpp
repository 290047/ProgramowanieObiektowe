#pragma once
#include "Osoba.hpp"
#include <iostream>

class ListaObecnosci
{
    public:
    ListaObecnosci(int len);
    ~ListaObecnosci();
    int Dodaj(Osoba *osoba);
    int Usun(Osoba *osoba);
    int UstawObecnosc(Osoba *osoba, bool obecna);
    bool JestObecna(Osoba *osoba);

    private:
    int pojemnosc;
    int iloscObecnych;
    bool *obecni;
    Osoba **osoby;
    int findIdx(Osoba *osoba);
};