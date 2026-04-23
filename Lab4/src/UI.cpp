#include "UI.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Intern.hpp"
#include <iostream>

UI::UI(Person **people, PresenceList **presenceLists, int listCount)
    : m_people{people},
      m_presenceLists{presenceLists},
      m_count{0},
      m_listCount{listCount},
      m_selectedList{-1}
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

            for(;;)
            {
                std::cout << "Student? (t/n): ";
                std::getline(std::cin >> std::ws, argString); // std::ws aby ignorowac spacje i enter

                if (argString[0] == 't')
                {
                    addStudent();
                    break;
                }
                else if(argString[0] == 'n')
                {
                    addIntern();
                    break;
                }
            }

            break;

        case 's':

            displayPeople();

            std::cout << "Ktory numer skreslic? "; std::cin >> argInt;
            argInt--; // wyswietlamy od 1 zatem uzytkownik tez wprowadza od 1

            if(argInt < 0 || argInt >= m_count)
            {
                std::cout << "Nie ma takiego numeru.\n";
                break;
            }

            removePerson(argInt);
            break;

        case 'i':

            std::cout << "INDEKS: "; std::cin >> argInt;
            changeName(argInt);

            break;

        case 'n':

            displayPeople();
            std::cout << "Wybierz numer do zmiany nazwiska: "; std::cin >> argInt;

            argInt--; // wyswietlamy od 1 zatem uzytkownik tez wprowadza od 1
            if(argInt < 0 || argInt >= m_count)
            {
                std::cout << "Nie ma takiego numeru.\n";
                break;
            }
            changeSurname(argInt);

            break;

        case 'u':

            displayPeople();

            std::cout << "Ustaw obecnosc dla numeru: "; std::cin >> argInt;

            argInt--; // wyswietlamy od 1 zatem uzytkownik tez wprowadza od 1
            if(argInt < 0 || argInt >= m_count)
            {
                std::cout << "Nie ma takiego numeru.\n";
                break;
            }

            currentList()->SetPresent(m_people[argInt], true);
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
    clearScreen();

    int id = -1;
    bool ok = false;

    do
    {
        std::cout << "Dostepne listy:\n";
        for (int i = 0; i < m_listCount; i++)
            std::cout << " [" << i << "] Lista " << i << "\n";

        std::cout << "Wybierz: ";
        std::cin >> id;

        ok = id >= 0 && id < m_listCount;

        if (!ok)
        {
            clearScreen();
            std::cout << "Nie ma takiej listy.\n";
        }
    } while (!ok);

    m_selectedList = id;
    clearScreen();
}

PresenceList *UI::currentList()
{
    return m_presenceLists[m_selectedList];
}

void UI::addStudent()
{
    if (m_count >= 10)
        return;

    Student *student = new Student();
    std::string argString;

    std::cout << "Dodaj IMIE: ";
    std::cin >> argString;
    if (student->SetName(argString) != 0)
    {
        std::cout << "Imie musi mieć 2+ znaki\n";
        delete student;
        return;
    }

    std::cout << "Dodaj NAZWISKO: ";
    std::cin >> argString;
    if (student->SetSurname(argString) != 0)
    {
        std::cout << "Nazwisko musi miec 2+ znaki\n";
        delete student;
        return;
    }

    int argInt;
    std::cout << "Dodaj INDEKS: ";
    std::cin >> argInt;
    if (student->SetIndex(argInt) != 0)
    {
        std::cout << "Niepoprawny indeks.\n";
        delete student;
        student = nullptr;
    }

    m_people[m_count] = student;
    currentList()->Add(student);
    m_count++;

    std::cout << "Dodano studenta.\n";
    student->Print('\n');
}

void UI::addIntern()
{
    if (m_count >= 10)
        return;

    Intern *intern = new Intern();
    std::string argString;

    std::cout << "Dodaj IMIE: ";
    std::cin >> argString;
    if (intern->SetName(argString) != 0)
    {
        std::cout << "Imie musi mieć 2+ znaki\n";
        delete intern;
        return;
    }

    std::cout << "Dodaj NAZWISKO: ";
    std::cin >> argString;
    if (intern->SetSurname(argString) != 0)
    {
        std::cout << "Nazwisko musi miec 2+ znaki\n";
        delete intern;
        return;
    }

    int argInt;
    std::cout << "Dodaj INDEKS: ";
    std::cin >> argInt;
    if (intern->SetId(argInt) != 0)
    {
        std::cout << "Niepoprawny indeks.\n";
        delete intern;
        intern = nullptr;
        return;
    }

    m_people[m_count] = intern;
    currentList()->Add(intern);
    m_count++;

    std::cout << "Dodano stazyste.\n";
    intern->Print('\n');
}

void UI::removePerson(int idx)
{
    std::cout << "Usuwamy: ";
    m_people[idx]->Print('\n');

    currentList()->Remove(m_people[idx]);
    delete m_people[idx];
    m_people[idx] = m_people[m_count - 1];
    (m_count)--;

}

void UI::changeName(int idx)
{
    std::string previous = m_people[idx]->GetName();

    std::string nName;
    std::cout << "Nowe imie: "; std::cin >> nName;

    if (m_people[idx]->SetName(nName) == -1)
        std::cout << "Imie musi miec 2+ znaki.\n";
    else
        std::cout << "Zmieniono imie: " << previous << " -> " << nName << '\n';
}

void UI::changeSurname(int idx)
{
    std::string previous = m_people[idx]->GetSurname();

    std::string nSurname;
    std::cout << "Nowe nazwisko: "; std::cin >> nSurname;

    if (m_people[idx]->SetSurname(nSurname) == -1)
        std::cout << "Nazwisko musi miec 2+ znaki.\n";
    else
        std::cout << "Zmieniono nazwisko: " << previous << " -> " << nSurname << '\n';
}

void UI::displayPeople()
{
    clearScreen();

    std::cout << "OSOBY:\n";

    int count = 0;
    int present = 0;
    for (int i = 0; i < m_count; i++)
    {
        int status = currentList()->IsPresent(m_people[i]);

        // ta osoba nie chodzi na te zajecia
        if (status == -1)
            continue;

        if (status == 1)
            present++;
        count++;

        std::cout << " [" << (count) << "]: ";
        m_people[i]->Print();

        std::cout << ((status == 1) ? "OBECNOSC" : "NIEOBECNOSC") << "\n";
    }
    std::cout << "OBECNI/WSZYSCY: " << present << '/' << count << '\n';
}

void UI::printMenu()
{
    std::cout << " - LISTA: " << m_selectedList
              << "\n(L)iste zmien"
              << " (D)odaj"
              << " (U)staw obecnosc"
              << " (W)yswietl"
              << " (S)kresl ze studiow"
              << " (I)mie zmien"
              << " (N)azwisko zmien"
              << " (Q)Wyjdz"
              << "\n>";
}