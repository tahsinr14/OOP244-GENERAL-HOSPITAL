/*
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 165063199
Date:  December 5, 2020
Email: trahman31@myseneca.ca
*/



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {

    Menu::Menu(const char* text, int NoOfSelections)
    {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
    }

    Menu::~Menu()
    {
        delete[] m_text;
        m_text = nullptr;
    }

    std::ostream& Menu::display(std::ostream& ostr)const
    {

        cout << m_text << '\n';
        cout << "0- Exit" << '\n';
        cout << "> ";

        return ostr;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        int value = -99;
        bool isValid = true;
        while (isValid) {
            if ((cin >> value))
            {
                isValid = !(value >= 0 && value <= m_noOfSel);

                if (isValid)
                    cout << "Invalid value enterd, retry[0 <= value <= 3]: ";
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Bad integer value, try again: ";
            }
        }
        Selection = value;

        return Selection;

    }

}