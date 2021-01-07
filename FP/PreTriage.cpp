/* Citation and Sources...
Final Project Milestone 5
Module: Pretriage
Filename: Pretriage.cpp
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 165063199
Date: December 5, 2020
Email: trahman31@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Time.h"
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		if (m_dataFilename != nullptr) {
			delete[] m_dataFilename;
		}
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {
		ofstream fout;
		int i;
		fout.open(m_dataFilename);
		if (fout) {
			fout << m_averCovidWait << "," << m_averTriageWait << endl;
			cout << "Saving Average Wait Times," << endl << "   COVID Test: " << m_averCovidWait << endl << "   Triage: " << m_averTriageWait << endl << "Saving m_lineup..." << endl;
			for (i = 0; i < m_lineupSize; i++)
			{
				m_lineup[i]->fileIO(true);
				fout << *m_lineup[i] << endl;
				cout << i + 1 << "- ";
				cout << *m_lineup[i] << endl;

				delete m_lineup[i];
			}
			fout.close();
			delete[] m_dataFilename;

			cout << "done!" << endl;
		}
	}
	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		int count = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				count++;
			}
		} Time time;
		time *= count;
		return time;
	}
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C')
			m_averCovidWait = ((sdds::getTime() - (Time)p) + (m_averCovidWait * (p.number() - 1))) / p.number();
		else if (p.type() == 'T')
			m_averTriageWait = ((sdds::getTime() - (Time)p) + (m_averTriageWait * (p.number() - 1))) / p.number();
		
	}
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int r = -1;

		for (int i = 0; i < m_lineupSize && r == -1; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				r = i;
			}
		}
		return r;
	}
	void PreTriage::load()
	{
		ifstream fin;
		cout << "Loading data..." << endl;
		fin.open(m_dataFilename);

		if (fin) {
			fin >> m_averCovidWait;
			fin.ignore(1000, ',');
			fin >> m_averTriageWait;
			fin.ignore(1000, '\n');
			char ch{};
			Patient* P = nullptr;
			for (int i = 0; i < maxNoOfPatients && !fin.eof(); i++) {
				fin >> ch;
				fin.ignore(1000, ',');
				if (fin.good()) {
					if (ch == 'C') {
						P = new CovidPatient();
					}
					else if (ch == 'T') {
						P = new TriagePatient();
					}

					if (P != nullptr) {
						P->fileIO(true);
						P->csvRead(fin);
						P->fileIO(false);
						m_lineup[i] = P;
						m_lineupSize++;
						P = nullptr;
					}
				}
			}
			if (!fin.eof() && fin) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}

			cout << m_lineupSize << " Records imported..." << endl << endl;
			fin.close();
		}
		else {
			cout << "No data or bad data file!" << endl << endl;
		}
	}

	void PreTriage::reg()
	{
		int selection;
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu >> selection;
			switch (selection)
			{
			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			}
			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->fileIO(false);
			cin >> *m_lineup[m_lineupSize];
			cout << endl << "******************************************" << endl;
			cout << *m_lineup[m_lineupSize];
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;
			m_lineupSize++;
		}
	}

	void PreTriage::admit()
	{
		int selection, nextP;
		char type = 'x';

		m_pMenu >> selection;
		switch (selection)
		{
		case 1:
			type = 'C';
			break;
		case 2:
			type = 'T';
			break;
		}
		nextP = indexOfFirstInLine(type);
		if (nextP != -1)
		{
			cout << endl << "******************************************" << endl;
			cout << "Calling for " << *m_lineup[nextP];
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[nextP]);
			removePatientFromLineup(nextP);
		}
	}
	void PreTriage::run(void)
	{
		int selection = 0;

		do {
			m_appMenu >> selection;
			switch (selection)
			{
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			default:
				break;
			}
		} while (selection != 0);

	}



		}
	
