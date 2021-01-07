/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 165063199
Date: November 24, 2020
Email: trahman31@myseneca.ca
*/
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

	class CovidPatient : public Patient {

	public:
		CovidPatient();
		virtual char type()const;
		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);

   
   };
}
#endif // !SDDS_COVIDPATIENT_H_



