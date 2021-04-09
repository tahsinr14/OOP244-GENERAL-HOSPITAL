/*
Final Project Milestone 4
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 
Date:  December 5, 2020
Email: trahman31@myseneca.ca
*/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& csvWrite(std::ostream& os)const = 0;
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {}
	};
	//helper functions
	std::ostream& operator<<(std::ostream& os, const IOAble& X);
	std::istream& operator>>(std::istream& istr, IOAble& Y);
}

#endif // !SDDS_IOABLE_H_
