/*
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 
Date: November 11, 2020
Email: trahman31@myseneca.ca
*/


#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   class Menu{
      char* m_text;
      int m_noOfSel;
   public:
      Menu(const char* text, int NoOfSelections);
      virtual ~Menu();
      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;
      std::ostream& display(std::ostream& ostr = std::cout)const;
      int& operator>>(int& Selection);
   };
}
#endif // !SDDS_MENU_H_
