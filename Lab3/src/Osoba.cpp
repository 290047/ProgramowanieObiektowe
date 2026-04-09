#include "Osoba.hpp"
#include <iostream>

Osoba::Osoba() :
    indeks(),
    imie(),
    nazwisko()
{

}

std::string Osoba::GetImie()     { return this->imie; };
std::string Osoba::GetNazwisko() { return this->nazwisko; };
int Osoba::GetIndeks()           { return this->indeks; };

int Osoba::SetImie(std::string imie)
{
    if(imie.size() < 2)
        return -1;

    this->imie = imie;
    return 0;
}

int Osoba::SetNazwisko(std::string nazwisko)
{
    if(nazwisko.size() < 2)
        return -1;
        
    this->nazwisko = nazwisko;
    return 0;
}

int Osoba::SetIndeks(int indeks)
{
    if(indeks < 0)
        return -1;
        
    this->indeks = indeks;
    return 0;
}