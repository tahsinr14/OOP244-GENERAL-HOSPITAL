/*
Final Project Milestone 4
Module: Time
Filename: Time.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds {

	Time& Time::reset() {
		m_min = getTime();
		return *this;
	}

	//set the time to zero by default
	Time::Time(unsigned int min) {
		m_min = min;
	}

	//Writes the time into a stream in HH:MM format
	std::ostream& Time::write(std::ostream& ostr) const
	{

		int hour = m_min / 60;
		int minute = m_min % 60;

		ostr << setfill('0')
			<< setw(2) << hour
			<< ":" << setw(2) << minute;

		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour, minute = 0;
		int characters;

		istr >> hour;
		characters = istr.get();

		if (characters == ':')
		{
			istr >> minute;
			m_min = hour * 60 + minute;
		}

		else
		{

			istr.setstate(ios::failbit);
		}
		return istr;

	}


	Time::operator int()const
	{
		return m_min;
	}

	Time& Time::operator*= (int val)
	{

		m_min *= val;
		return *this;
	}

	Time& Time::operator-= (const Time& D)
	{
		int timeDiff = -1;
		if (m_min < D.m_min) {
			timeDiff = (m_min + (24 * 60)) - D.m_min;
		}
		else {
			timeDiff = m_min - D.m_min;
		}
		m_min = timeDiff;
		return *this;
	}

	ostream& operator<<(ostream& os, const Time& time_Obj)
	{

		time_Obj.write(os);

		return os;
	}

	istream& operator>>(istream& istr, Time& time_Obj)
	{

		time_Obj.read(istr);
		return istr;

	}
}
