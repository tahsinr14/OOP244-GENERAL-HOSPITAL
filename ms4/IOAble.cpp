/*
Final Project Milestone 4
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 
Date: November 24, 2020
Email: trahman31@myseneca.ca
*/

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& os, const IOAble& X) {
		X.write(os);
		return os;
	}
	istream& operator>>(istream& istr, IOAble& Y) {
		Y.read(istr);
		return istr;
	}
}
