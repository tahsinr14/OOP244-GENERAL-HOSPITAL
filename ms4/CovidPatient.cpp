/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "Patient.h"
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {

	   nextCovidTicket++;
   }

   char CovidPatient::type() const 
   {
	   return 'C';
   }
   ostream& CovidPatient::csvWrite(ostream& os) const 
   {
	   Patient::csvWrite(os);
	   return os;
   }
   istream& CovidPatient::csvRead(istream& istr) 
   {
	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   return istr;
   }
   ostream& CovidPatient::write(ostream& os) const 
   {
	   //bool ok = true;
	   if (fileIO()==true) {
		   csvWrite(os);
	   }
	   else
	   {
		   os << "COVID TEST" << '\n';
		   Patient::write(os);
		   os << '\n';
	   }

	   return os;
   }
   istream& CovidPatient::read(istream& istr) 
   {
	   if (fileIO()==true) {
		   csvRead(istr);
	   }
	   else {
		   Patient::read(istr);
	   }
	   return istr;
   }

}
