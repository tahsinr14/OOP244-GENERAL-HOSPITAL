/*
Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
Version 1.1
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
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticket, bool flag) :m_ticket(ticket)
	{
		//m_ticket = ticket;

		fileIOf = flag;
	}

	Patient::~Patient()
	{

		delete[] m_pname;
		m_pname = nullptr;
	}

	bool Patient::fileIO()const
	{
		return fileIOf;
	}

	void Patient::fileIO(bool value)
	{
		fileIOf = value;
	}

	bool Patient::operator==(char x)const
	{
		return type() == x;
	}

	bool Patient:: operator==(Patient const& P2)const
	{
		return type() == P2.type();

	}

	void Patient::setArrivalTime()
	{

		m_ticket.resetTime();
	}

	Patient::operator Time ()const
	{
		return m_ticket;
	}

	int Patient::number()const
	{
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << ',' << m_pname << ',' << m_ohip << ',';
		m_ticket.csvWrite(ostr);
		return ostr;

	}

	istream& Patient::csvRead(std::istream& istr)
	{
		char nOfPatient[51];
		istr.get(nOfPatient, 51, ',');
		delete[] m_pname;
		m_pname = nullptr;
		m_pname = new char[strlen(nOfPatient) + 1];
		strcpy(m_pname, nOfPatient);
		istr.ignore(1000, ',');
		istr >> m_ohip;
		istr.ignore(1000, ',');
		m_ticket.csvRead(istr);
		return istr;
	}

	ostream& Patient::write(std::ostream& ostr) const
	{
		ostr << m_ticket << '\n' << m_pname << ", OHIP: " << m_ohip;
		return ostr;
	}

	istream& Patient::read(std::istream& istr)
	{
		cout << "Name: ";
		char nOfPatient[51];
		bool valid = true;
		istr.get(nOfPatient, '\n');
		delete[]m_pname;
		m_pname = nullptr;
		m_pname = new char[strlen(nOfPatient) + 1];
		strcpy(m_pname, nOfPatient);

		istr.ignore(1000, '\n');
		cout << "OHIP: ";
		//istr >> m_ohip;
		while (valid) {
			if ((m_ohip = getInt())) {
				valid = !(m_ohip >= 100000000 && m_ohip <= 999999999);
				if (valid) {
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";

				}
			}
			else {
				valid = false;
			}

		}
		return istr;
	}
}
