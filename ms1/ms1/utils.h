/* 
Final Project Milestone 1
Module: utils
Filename: utils.h
Version 1.0
Author	John Doe
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Name: Tahsin Rahman
Student ID: 165063199
Date: November 11, 2020
Email: trahman31@myseneca.ca
*/
//professor provided code

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   int getInt();
   int getTime(); // returns the time of day in minutes

   extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                      // all the files which include: "utils.h" 
                      //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_

