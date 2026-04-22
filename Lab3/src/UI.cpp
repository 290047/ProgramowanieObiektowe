#include "UI.hpp"
#include <iostream>

UI::UI(Person **people, PresenceList **presenceLists, int listCount)
    : _people{people},
      _presenceLists{presenceLists},
      _count{0},
      _listCount{listCount},
      _selectedList{-1}
{
}

namespace
{
    void clearScreen() // Kod czyszczacy okno konsoli
    {
        std::cout << "\033[2J\033[1;1H";
    }
}

void UI::Loop()
{
    selectList();

    char cmd;
    int argInt;
    std::string argString;

    Person *person;
    int status = 0;

    while (1)
    {
        printMenu();
        std::cin >> cmd;
        clearScreen();

        switch (tolower(cmd))
        {
        case 'l':
            selectList();
            break;

        case 'd':

            person = new Person();

            std::cout << "Dodaj INDEKS: ";
            std::cin >> argInt;
            if (findIdx(argInt) != -1 || person->SetIndex(argInt) != 0)
            {
                std::cout << "Niepoprawny indeks.\n";
                delete person;
                person = nullptr;
                break;
            }

            std::cout << "Dodaj IMIE: ";
            std::cin >> argString;
            if (person->SetName(argString) != 0)
            {
                std::cout << "Imie musi mieć 2+ znaki\n";
                delete person;
                person = nullptr;
                break;
            }

            std::cout << "Dodaj NAZWISKO: ";
            std::cin >> argString;
            if (person->SetSurname(argString) != 0)
            {
                std::cout << "Nazwisko musi miec 2+ znaki\n";
                delete person;
                person = nullptr;
                break;
            }

            addPerson(person);
            break;

        case 's':

            std::cout << "Skresl INDEKS: ";
            std::cin >> argInt;
            if (removePerson(argInt) != 0)
                std::cout << "Brak osoby z takim indeksem.\n";
            break;

        case 'i':

            std::cout << "INDEKS: ";
            std::cin >> argInt;
            std::cout << "Nowe IMIE: ";
            std::cin >> argString;

            status = changeName(argInt, argString);
            if (status == -1)
                std::cout << "Brak osoby z takim indeksem.\n";
            else if (status == -2)
                std::cout << "Imie musi mieć 2+ znaki.\n";

            break;

        case 'n':

            std::cout << "INDEKS: ";
            std::cin >> argInt;
            std::cout << "Nowe NAZWISKO: ";
            std::cin >> argString;

            status = changeSurname(argInt, argString);
            if (status == -1)
                std::cout << "Brak osoby z takim indeksem.\n";
            else if (status == -2)
                std::cout << "Nazwisko musi mieć 2+ znaki.\n";

            break;

        case 'u':

            std::cout << "Ustaw obecnosc dla indeksu: ";
            std::cin >> argInt;
            argInt = findIdx(argInt);

            if (argInt != -1)
                currentList()->SetPresent(_people[argInt], true);
            else
                std::cout << "Brak osoby z takim indeksem.\n";

            break;

        case 'w':

            displayPeople();
            break;

        case 'q':
            return;

        default:
            std::cout << "Nieznana komenda.\n";
        }
    }
}

void UI::selectList()
{
    int id = -1;
    bool ok = false;

    do
    {
        std::cout << "Dostepne listy:\n";
        for (int i = 0; i < _listCount; i++)
            std::cout << " [" << i << "] Lista " << i << "\n";

        std::cout << "Wybierz: ";
        std::cin >> id;

        ok = id >= 0 && id < _listCount;

        if (!ok)
        {
            clearScreen();
            std::cout << "Nie ma takiej listy.\n";
        }
    } while (!ok);

    _selectedList = id;
}

PresenceList *UI::currentList()
{
    return _presenceLists[_selectedList];
}

void UI::addPerson(Person *nPerson)
{
    if (_count >= 10)
        return;

    _people[_count] = nPerson;
    currentList()->Add(nPerson);
    (_count)++;
}

// Kody błędów:
// -1: Brak osoby z takim indeksem
int UI::removePerson(int indeks)
{
    for (int i = 0; i < _count; i++)
    {
        if (_people[i]->GetIndex() == indeks)
        {
            currentList()->Remove(_people[i]);
            delete _people[i];
            _people[i] = _people[_count - 1];
            (_count)--;
            return 0;
        }
    }
    return -1;
}

// Kody błędów:
// -1: Brak osoby z takim indeksem
// -2: Nowe imie ma <2 znaki
int UI::changeName(int indeks, std::string nImie)
{
    int idx = findIdx(indeks);
    if (idx == -1)
        return -1;
    if (_people[idx]->SetName(nImie) == -1)
        return -2;
    return 0;
}

// Kody błędów:
// -1: Brak osoby z takim indeksem
// -2: Nowe nazwisko ma <2 znaki
int UI::changeSurname(int indeks, std::string nNazwisko)
{
    int idx = findIdx(indeks);
    if (idx == -1)
        return -1;
    if (_people[idx]->SetSurname(nNazwisko) == -1)
        return -2;
    return 0;
}

void UI::displayPeople()
{
    std::cout << "OSOBY:\n";

    int count = 0; int present = 0;
    for (int i = 0; i < _count; i++)
    {
        int status = currentList()->IsPresent(_people[i]);

        // ta osoba nie chodzi na te zajecia
        if(status == -1) continue;
        if(status == 1) present++;
        count++;
            
        std::cout << " [" << (count) << "]: "
                  << "(" << _people[i]->GetIndex() << ") "
                  << _people[i]->GetName() << " "
                  << _people[i]->GetSurname() << " "
                  << ((status == 1) ? "OBECNOSC" : "NIEOBECNOSC")
                  << "\n";
    }
    std::cout << "OBECNI/WSZYSCY: " << present << '/' << count << '\n';
}

void UI::printMenu()
{
    std::cout << "--- Menu --- LISTA: " << _selectedList
              << "\n(L)iste zmien"
              << " (D)odaj"
              << " (U)staw obecnosc"
              << " (W)yswietl"
              << " (S)kresl ze studiow"
              << " (I)mie zmien"
              << " (N)azwisko zmien"
              << " (Q)Wyjdz"
              << "\n:";
}

int UI::findIdx(int indeks)
{
    for (int i = 0; i < _count; i++)
        if (_people[i]->GetIndex() == indeks)
            return i;
    return -1;
}