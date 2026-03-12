#include <iostream>

using namespace std;

const int N = 10;

// API

void dodajOsobe(int *indeksy, std::string *imiona, std::string *nazwiska, bool *obecnosc, int *count,
    int nIndeks, std::string nImie, std::string nNazwisko)
{
    if(*count >= 10)
        return;

    indeksy[*count]  = nIndeks;
    imiona[*count]   = nImie;
    nazwiska[*count] = nNazwisko;
    obecnosc[*count] = false;

    (*count)++;
}

void usunOsobe(int *indeksy, std::string *imiona, std::string *nazwiska, bool *obecnosc, int *count,
    int indeks)
{
    for(int i = 0; i < *count; i++)
    {
        if(indeksy[i] == indeks)
        {
            indeksy[i]  = indeksy[*count - 1];
            imiona[i]   = imiona[*count - 1];
            nazwiska[i] = nazwiska[*count - 1];
            obecnosc[i] = obecnosc[*count - 1];
            (*count)--;
            return;
        }
    }
}

void zmienImie(int *indeksy, std::string *imiona, int count,
    int indeks, std::string nImie)
{
    for(int i = 0; i < count; i++)
    {
        if(indeksy[i] == indeks)
        {
            imiona[i] = nImie;
            return;
        }
    }
}

void zmienNazwisko(int *indeksy, std::string *nazwiska, int count,
    int indeks, std::string nNazwisko)
{
    for(int i = 0; i < count; i++)
    {
        if(indeksy[i] == indeks)
        {
            nazwiska[i] = nNazwisko;
            return;
        }
    }
}

void ustawObecnosc(int *indeksy, bool *obecnosc, int *count, int indeks,
    bool obecna)
{
    for(int i = 0; i < *count; i++)
    {
        if(indeksy[i] == indeks)
            obecnosc[i] = obecna;
    }
}

void wyswietlListe(int *indeksy, std::string *imiona, std::string *nazwiska, bool *obecnosc, int *count)
{
    for(int i = 0; i < *count; i++)
    {
        std::cout << "(" << (i+1) << "): "
                  << "(" << indeksy[i]  << ") "
                  << imiona[i] << " "
                  << nazwiska[i] << " "
                  << (obecnosc[i] ? "OBECNOSC" : "NIEOBECNOSC")
                  << "\n";
    }
}

int main()
{
    int count = 0;

    std::string imiona[N];
    std::string nazwiska[N];
    int indeksy[N];
    bool obecnosc[N];


    char cmd;
    int indeks;
    std::string imie, nazwisko;

    while(1)
    {
        std::cout << "--- (D)odaj (U)staw (W)yswietl (S)kresl z listy (I)mie zmien (N)azwisko zmien\n";
        std::cin >> cmd;

        switch (tolower(cmd))
        {
            case 'd':

                std::cout << "Dodaj INDEKS: ";
                std::cin >> indeks;

                std::cout << "Dodaj IMIE: ";
                std::cin >> imie;

                std::cout << "Dodaj NAZWISKO: ";
                std::cin >> nazwisko;

                dodajOsobe(indeksy, imiona, nazwiska, obecnosc, &count, indeks, imie, nazwisko);
                break;

            case 's':

                std::cout << "Skresl INDEKS: ";
                std::cin >> indeks;
                usunOsobe(indeksy, imiona, nazwiska, obecnosc, &count, indeks);
                break;

            case 'i':

                std::cout << "INDEKS: ";
                std::cin >> indeks;
                std::cout << "Nowe IMIE: ";
                std::cin >> imie;
                zmienImie(indeksy, imiona, count, indeks, imie);
                break;

            case 'n':

                std::cout << "INDEKS: ";
                std::cin >> indeks;
                std::cout << "Nowe NAZWISKO: ";
                std::cin >> nazwisko;
                zmienNazwisko(indeksy, imiona, count, indeks, nazwisko);
                break;

            case 'u':

                std::cout << "Ustaw obecnosc dla indeksu: ";
                std::cin >> indeks;
                ustawObecnosc(indeksy, obecnosc, &count, indeks, true);
                break;

            case 'w':

                wyswietlListe(indeksy, imiona, nazwiska, obecnosc, &count);
                break;

            default:
                std::cout << "Nieznana komenda.\n";
        }
    }
}