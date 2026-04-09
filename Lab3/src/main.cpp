#include <iostream>
#include "Osoba.hpp"
#include "ListaObecnosci.hpp"

const int N = 10;

void dodajOsobe(Osoba **osoby, ListaObecnosci *lista, int *count, Osoba* nOsoba)
{
    if (*count >= 10)
        return;

    osoby[*count] = nOsoba;
    lista->Dodaj(nOsoba);
    (*count)++;
}

void usunOsobe(Osoba **osoby, ListaObecnosci *lista, int *count, int indeks)
{
    for (int i = 0; i < *count; i++)
    {
        if (osoby[i]->GetIndeks() == indeks)
        {
            lista->Usun(osoby[i]);
            delete osoby[i];
            osoby[i] = osoby[*count - 1];
            (*count)--;
            return;
        }
    }
}

int findIdx(Osoba **osoby, int *count, int indeks)
{
    for (int i = 0; i < *count; i++)
        if (osoby[i]->GetIndeks() == indeks)
            return i;
    return -1;
}

void zmienImie(Osoba **osoby, int *count, int indeks, std::string nImie)
{
    int idx = findIdx(osoby, count, indeks);
    if(idx != -1)
        osoby[idx]->SetImie(nImie);
}

void zmienNazwisko(Osoba **osoby, int *count, int indeks, std::string nNazwisko)
{
    int idx = findIdx(osoby, count, indeks);
    if(idx != -1)
        osoby[idx]->SetNazwisko(nNazwisko);
}

void wyswietlOsoby(Osoba **osoby, ListaObecnosci* lista, int *count)
{
    std::cout << "OSOBY:\n";

    for (int i = 0; i < *count; i++)
    {
        std::cout << "[" << (i + 1) << "]: "
                  << "(" << osoby[i]->GetIndeks() << ") "
                  << osoby[i]->GetImie() << " "
                  << osoby[i]->GetNazwisko() << " "
                  << (lista->JestObecna(osoby[i]) ? "OBECNOSC" : "NIEOBECNOSC")
                  << "\n";
    }
}

void printMenu() {
    std::cout << "--- Menu ---\n"
              << " (D)odaj"
              << " (U)staw obecnosc"
              << " (W)yswietl"
              << " (S)kresl z listy"
              << " (I)mie zmien"
              << " (N)azwisko zmien"
              << " (Q)Wyjdz"
              << "\n:";
}

void run(Osoba **osoby, ListaObecnosci* obecnosci, int *count)
{
    char cmd;
    int argInt;
    std::string argString;
    
    Osoba *osoba;

    while (1)
    {
        printMenu();
        std::cin >> cmd;

        switch (tolower(cmd))
        {
        case 'd':

            osoba = new Osoba();

            std::cout << "Dodaj INDEKS: "; std::cin >> argInt;
            if(findIdx(osoby, count, argInt) != -1 || osoba->SetIndeks(argInt) != 0)
            {
                std::cout << "Niepoprawny indeks.\n";
                delete osoba; osoba = nullptr;
                break;
            }

            std::cout << "Dodaj IMIE: ";
            std::cin >> argString;
            if(osoba->SetImie(argString) != 0)
            {
                std::cout << "Dlugosc imienia musi byc dluzsza niz 1.\n";
                delete osoba; osoba = nullptr;
                break;
            }

            std::cout << "Dodaj NAZWISKO: ";
            std::cin >> argString;
            if(osoba->SetNazwisko(argString) != 0)
            {
                std::cout << "Dlugosc nazwiska musi byc dluzsza niz 1.\n";
                delete osoba; osoba = nullptr;
                break;
            }

            dodajOsobe(osoby, obecnosci, count, osoba);
            break;

        case 's':

            std::cout << "Skresl INDEKS: "; std::cin >> argInt;
            usunOsobe(osoby, obecnosci, count, argInt);
            break;

        case 'i':

            std::cout << "INDEKS: ";    std::cin >> argInt;
            std::cout << "Nowe IMIE: "; std::cin >> argString;
            zmienImie(osoby, count, argInt, argString);
            break;

        case 'n':

            std::cout << "INDEKS: ";        std::cin >> argInt;
            std::cout << "Nowe NAZWISKO: "; std::cin >> argString;
            zmienNazwisko(osoby, count, argInt, argString);
            break;

        case 'u':

            std::cout << "Ustaw obecnosc dla indeksu: ";
            std::cin >> argInt;
            argInt = findIdx(osoby, count, argInt);

            if(argInt != -1)
                obecnosci->UstawObecnosc(osoby[argInt], true);
            else
                std::cout << "Nie znaleziono osoby.\n";

            break;

        case 'w':

            wyswietlOsoby(osoby, obecnosci, count);
            break;

        case 'q':
            return;

        default:
            std::cout << "Nieznana komenda.\n";
        }
    }
}

int main()
{
    int count = 0;
    Osoba *osoby[N] = {nullptr};
    ListaObecnosci *obecnosci = new ListaObecnosci(N);

    run(osoby, obecnosci, &count);

    for(int i = 0; i < count; i++)
        delete osoby[i];
    delete obecnosci;
}