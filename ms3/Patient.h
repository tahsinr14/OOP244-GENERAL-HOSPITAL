/*
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.1
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 165063199
Date: November 19, 2020
Email: trahman31@myseneca.ca
*/
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	class Patient :public IOAble {
		char* m_pname = nullptr; //patient name
		int long m_ohip = 0;
		Ticket m_ticket;
		bool fileIOf = false;

	public:
		//Patient();
		Patient(int ticket = 0, bool flag = false);
		Patient(const Patient& P) = delete;
		Patient& operator=(const Patient& P1) = delete;
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool value);

		bool operator==(char x)const;
		bool operator==(Patient const& P2)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);


	};

}
#endif // !SDDS_PATIENT_H_


