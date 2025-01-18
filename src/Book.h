/*********************************************************
* Summary: This file declares all the methods used for the Book   
*          base class for Project 1: Library Management System
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

#ifndef BOOK_H
#define BOOK_H

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

using namespace std;

class Book{
  protected:
    // member variables for Book base class
    string title;
    string author;
    string ISBN;
    string genre;
    bool available;
    string borrowedBy;
  public:
    // constructors 
    Book();
    Book(const string& title, const string& author, const string& ISBN, const string& genre);
    Book(const string& title, const string& author, const string& ISBN, const string& genre, bool available, const string& borrowedBy);

    // accessors 
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getGenre() const;
    bool getAvailable() const;
    string getBorrowedby() const;

    // mutators 
    void setTitle(const string& newTitle);
    void setAuthor(const string& newAuthor);
    void setISBN(const string& newISBN);
    void setGenre(const string& newGenre);
    void setAvailable(bool newAvailability);
    void setBorrowedBy(const string& newBorrower);

    // virtual function to display book details
    virtual void displayInfo() const;

    // display book information
    friend ostream& operator<<(ostream& os, const Book& book);

    // input book information
    friend istream& operator>>(istream& is, Book& book);

    // friend classes 
    friend class Library;
    friend class Member; 
};

#endif // BOOK_H