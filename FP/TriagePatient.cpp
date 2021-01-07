/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include<iostream>
#include<iomanip>
#include <cstring>
#include "TriagePatient.h"

using namespace std;
namespace sdds
{
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket), symptoms(nullptr)
	{

		nextTriageTicket++;

	}
	char TriagePatient::type()const
	{
		return 'T';
	}
	ostream& TriagePatient::csvWrite(ostream& os) const
	{
		Patient::csvWrite(os);
		os << ',';
		os << symptoms;
		return os;
	}
	istream& TriagePatient::csvRead(istream& istr)
	{
		int const arrSize = 512;
		char symptoms_arr[arrSize];
		delete[] symptoms;
		symptoms = nullptr;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		istr.get(symptoms_arr, arrSize, '\n');
		symptoms = new char[strlen(symptoms_arr) + 1];
		strcpy(symptoms, symptoms_arr);
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}
	ostream& TriagePatient::write(ostream& os) const
	{
		if (fileIO()) {
			csvWrite(os);
		}
		else {
			os << "TRIAGE" << '\n';
			Patient::write(os);
			os << '\n';
			os << "Symptoms: ";
			os << symptoms;
			os << '\n';
		}
		return os;
	}
	istream& TriagePatient::read(istream& istr)
	{
		int const arrSize = 512;
		char arrOfSymp[arrSize];
		if (fileIO()) {
			csvRead(istr);
		}
		else
		{
			delete[] symptoms;
			symptoms = nullptr;
			Patient::read(istr);
			cout << "Symptoms: ";
			istr.get(arrOfSymp, arrSize, '\n');
			istr.ignore();
			symptoms = new char[strlen(arrOfSymp) + 1];
			strcpy(symptoms, arrOfSymp);
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] symptoms;
		symptoms = nullptr;
	}
}