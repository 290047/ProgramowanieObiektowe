#include "ListaObecnosci.hpp"
#include "Osoba.hpp"

ListaObecnosci::ListaObecnosci(int len) : pojemnosc{len}, iloscObecnych{0}
{
    this->osoby = new Osoba*[len];
    this->obecni = new bool[len];
}

ListaObecnosci::~ListaObecnosci()
{
    delete[] this->osoby;
    delete[] this->obecni;
}

// Kody błędów:
// -1: nie można dodać - max liczba osób osiągnięta
// -2: ta sama osoba już jest na liście
int ListaObecnosci::Dodaj(Osoba *osoba)
{
    if(this->iloscObecnych >= this->pojemnosc)
        return -1;
    
    if(findIdx(osoba) != -1)
        return -2;
    
    this->osoby[iloscObecnych] = osoba;
    this->obecni[iloscObecnych] = false;
    this->iloscObecnych++;

    return 0;
}

// Kody błędów:
// -1: na liście nie ma tej osoby lub nie ma wcale osób
int ListaObecnosci::Usun(Osoba *osoba)
{
    int idx = findIdx(osoba);
    if(idx == -1)
        return -1;
    
    // usunięcie przez podmianę
    this->osoby[idx] = this->osoby[iloscObecnych-1];
    this->obecni[idx] = this->obecni[iloscObecnych-1];
    this->iloscObecnych--;
    return 0;
}

// Kody błędów:
// -1: na liście nie ma takiej osoby
int ListaObecnosci::UstawObecnosc(Osoba *osoba, bool obecna)
{
    int idx = findIdx(osoba);
    if(idx == -1)
        return -1;

    obecni[idx] = obecna;
    return 0;
}

bool ListaObecnosci::JestObecna(Osoba *osoba)
{
    int idx = findIdx(osoba);
    return idx == -1 ? false : obecni[idx];
}

int ListaObecnosci::findIdx(Osoba *osoba)
{
    for(int i = 0; i < iloscObecnych; i++)
    {
        if(osoby[i]->GetIndeks() == osoba->GetIndeks())
            return i;
    }

    return -1;
}