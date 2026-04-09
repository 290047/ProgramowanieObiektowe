#pragma once
#include <iostream>

class Osoba
{
    public:
    Osoba();
    std::string GetImie();
    std::string GetNazwisko();
    int GetIndeks();
    int SetImie(std::string imie);
    int SetNazwisko(std::string nazwisko);
    int SetIndeks(int indeks);

    private:
    int indeks;
    std::string imie;
    std::string nazwisko;
};