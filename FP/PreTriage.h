/* Citation and Sources...
Final Project Milestone 5
Module: Pretriage
Filename: Pretriage.h
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

#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "Patient.h"
#include "Menu.h"
namespace sdds {
   const int maxNoOfPatients = 100;
   class PreTriage {
      Time 
         m_averCovidWait, 
         m_averTriageWait;
      Patient* m_lineup[maxNoOfPatients]{};
      char* m_dataFilename{};
      int m_lineupSize = 0;
      Menu m_appMenu, m_pMenu;
      void reg();
      void admit();
      const Time getWaitTime(const Patient& p)const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      void load();
      int indexOfFirstInLine(char type) const;
   public:
      PreTriage(const char* dataFilename);
      ~PreTriage();
      void run(void);
   };
}
#endif // !SDDS__H_
