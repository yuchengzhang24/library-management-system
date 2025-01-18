/*********************************************************
* Summary: This file declares all the methods used for the Audiobook  
*          derived base class for Project 1: Library Management System
*
*  
*
* Author: Yucheng Zhang
* Created: November 24, 2024
* Summary of Modifications [if applicable]:
*      24 Nov 2024 - Created file, declared data and methods. 
*
*
********************************************************/

#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <iostream>
#include <string>
#include <vector> 
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>
#include <cmath>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <map>
#include "Book.h"

using namespace std;

class Audiobook : public Book{
  private:
    int duration; // in minutes
    string narrator;
  public: 
    // constructors 
    Audiobook();
    Audiobook(const string& title, const string& author, const string& ISBN, const string& genre, int duration, const string& narrator);

    // accessors 
    int getDuration() const;
    string getNarrator() const;

    // mutators 
    void setDuration(int newDuration);
    void setNarrator(const string& newNarrator);

    // override displayInfo method to display audiobook info
    void displayInfo() const override;
};

#endif //AUDIOBOOK_H