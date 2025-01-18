/*********************************************************
* Summary: This file defines all the methods declared in   
*          Audiobook.h for Project 1: Library Management System
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
#include "Audiobook.h"

using namespace std;

// default constructor 
Audiobook::Audiobook()
         : Book(), duration(0), narrator(""){}

// parametized constructor 
Audiobook::Audiobook(const string& aTitle, const string& aAuthor, const string& aISBN, const string& aGenre, int aDuration, const string& aNarrator)
         : Book(aTitle, aAuthor, aISBN, aGenre), duration(aDuration), narrator(aNarrator){}

// getters 
int Audiobook::getDuration() const{
  return duration;
}
string Audiobook::getNarrator() const{
  return narrator;
}

// setters 
void Audiobook::setDuration(int newDuration){
  duration = newDuration;
}
void Audiobook::setNarrator(const string& newNarrator){
  narrator = newNarrator;
}

// override displayInfo method to display audiobook info
void Audiobook::displayInfo() const {
  Book::displayInfo();
  cout << "Duration: " << duration << " minutes" << endl;
  cout << "Narrator: " << narrator << endl;
  cout << "Format: Audiobook" << endl;
}