#include "UI.hpp"
#include <iostream>

UI::UI(Person **people, PresenceList *presence) : _people{people},
                                                  _presenceList{presence},
                                                  _count{0}
{
}

void UI::Loop()
{
    char cmd;
    int argInt;
    std::string argString;
    Person *person;
    int status = 0;

    while (1)
    {
        printMenu();
        std::cin >> cmd;

        switch (tolower(cmd))
        {
        case 'd':

            person = new Person();

            std::cout << "Add INDEKS: ";
            std::cin >> argInt;
            if (findIdx(argInt) != -1 || person->SetIndex(argInt) != 0)
            {
                std::cout << "Niepoprawny indeks.\n";
                delete person;
                person = nullptr;
                break;
            }

            std::cout << "Add IMIE: ";
            std::cin >> argString;
            if (person->SetName(argString) != 0)
            {
                std::cout << "Dlugosc imienia musi byc dluzsza niz 1.\n";
                delete person;
                person = nullptr;
                break;
            }

            std::cout << "Add NAZWISKO: ";
            std::cin >> argString;
            if (person->SetSurname(argString) != 0)
            {
                std::cout << "Dlugosc nazwiska musi byc dluzsza niz 1.\n";
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
            if(status == -1)
                std::cout << "Brak osoby z takim indeksem.\n";
            else
            if(status == -2)
                std::cout << "Nowe imie musi mieć co najmniej 2 znaki.\n";

            break;

        case 'n':

            std::cout << "INDEKS: ";
            std::cin >> argInt;
            std::cout << "Nowe NAZWISKO: ";
            std::cin >> argString;

            status = changeSurname(argInt, argString);
            if(status == -1)
                std::cout << "Brak osoby z takim indeksem.\n";
            else
            if(status == -2)
                std::cout << "Nowe nazwisko musi mieć co najmniej 2 znaki.\n";

            break;

        case 'u':

            std::cout << "Ustaw obecnosc dla indeksu: ";
            std::cin >> argInt;
            argInt = findIdx(argInt);

            if (argInt != -1)
                _presenceList->SetPresent(_people[argInt], true);
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

void UI::addPerson(Person *nPerson)
{
    if (_count >= 10)
        return;

    _people[_count] = nPerson;
    _presenceList->Add(nPerson);
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
            _presenceList->Remove(_people[i]);
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
    if (idx == -1) return -1;
    if (_people[idx]->SetName(nImie) == -1) return -2;
    return 0;
}

// Kody błędów:
// -1: Brak osoby z takim indeksem
// -2: Nowe nazwisko ma <2 znaki
int UI::changeSurname(int indeks, std::string nNazwisko)
{
    int idx = findIdx(indeks);
    if (idx == -1) return -1;
    if(_people[idx]->SetSurname(nNazwisko) == -1) return -2;
    return 0;
}

void UI::displayPeople()
{
    std::cout << "OSOBY:\n";

    for (int i = 0; i < _count; i++)
    {
        std::cout << "[" << (i + 1) << "]: "
                  << "(" << _people[i]->GetIndex() << ") "
                  << _people[i]->GetName() << " "
                  << _people[i]->GetSurname() << " "
                  << (_presenceList->IsPresent(_people[i]) ? "OBECNOSC" : "NIEOBECNOSC")
                  << "\n";
    }
}

void UI::printMenu()
{
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

int UI::findIdx(int indeks)
{
    for (int i = 0; i < _count; i++)
        if (_people[i]->GetIndex() == indeks)
            return i;
    return -1;
}