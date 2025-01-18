/*********************************************************
* Summary: This file declares all the methods used for the Member
*          Derived Class for Project 1: Library Management System
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

#ifndef MEMBER_H
#define MEMBER_H

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

class Member{
  private:
    // member variables for Member Class
    string memberID;                  
    string name;                       
    string email;
    vector<Book*> checkedOutBooks;
    map<Book*, time_t> dueDates;
    double lateFeePerDay = 1.0;   
  public:
    // constructors 
    Member();
    Member(const string& memberID, const string& name, const string& email);

    // accessors 
    string getMemberID() const;
    string getName() const;
    string getEmail() const;
    vector<Book*> getCheckedOutBooks() const;

    // mutators 
    void setMemberID(const string& memberID);
    void setName(const string& name);
    void setEmail(const string& email);
    void setLateFeePerDay(double fee);

    // member functions for borrowing and returning books
    void borrowBook(Book* book);
    void returnBook(const string& bookTitle);

    // functions to handle due dates and late fees
    void setDueDate(Book* book, int days);  
    bool isBookOverdue(Book* book) const;   
    double calculateLateFee(Book* book) const; 

    // display member information
    friend ostream& operator<<(ostream& os, const Member& member);

    // input member information
    friend istream& operator>>(istream& is, Member& member);

    // friend classes 
    friend class Library;
};

#endif // MEMBER_H