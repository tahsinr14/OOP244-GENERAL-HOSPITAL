/*
Final Project Milestone 4
Module: Time
Filename: Time.h
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 
Date: December 5, 2020
Email: trahman31@myseneca.ca
*/


#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time& operator-(const Time& ROperand);

       
    };
    // helper operator << and >> prototypes
    std::ostream& operator<<(std::ostream& os, const Time& time_Obj);
    std::istream& operator>>(std::istream& istr, Time& time_Obj);

   
}

#endif // !SDDS_TIME_H

