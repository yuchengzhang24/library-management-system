/*********************************************************
* Summary: This file declares all the methods used for the Library   
*          class for Project 1: Library Management System
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

#ifndef LIBRARY_H
#define LIBRARY_H

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
#include "Member.h"

using namespace std;

class Library{
  private: 
    // member variables for Library Class
    vector<Book*> books;
    vector<Member*> members;

    // counters to generate report 
    int booksAdded = 0;
    int booksRemoved = 0;
    int membersAdded = 0;
    int membersRemoved = 0;

  public:
    // constructor 
    Library();

    // accessors 
    vector<Book*>& getBooks();
    vector<Member*>& getMembers();

    // find a book by title
    bool findBook(const string& title) const;
    // get a book by title
    Book* getBookByTitle(const string& bookTitle) const;
    // add a book
    void addBook();
    // remove a book
    void removeBook();
    // display books
    void displayBooks() const;

    // find a member by ID
    bool findMember(const string& memberID) const;
    // get a member by ID 
    Member* getMemberByID(const string& memberID) const;
    // add a member
    void addMember();
    // remove a member
    void removeMember();
    // display members
    void displayMembers() const;

    // operator overloading for Book
    friend void operator+(vector<Book*>& books, Book*);
    friend void operator-(vector<Book*>& books, const string& bookTitle);

    // operator overloading for Member
    friend void operator+(vector<Member*>& members, Member*);
    friend void operator-(vector<Member*>& members, const string& memberID);
    
    // read books from file into library 
    void readBooksFromFile(const string& fileName);

    // read members from file into library
    void readMembersFromFile(const string& fileName);

    // check out a book
    void checkOutBook(const string& memberID, const string& bookTitle);

    // return a book
    void returnBook(const string& memberID, const string& bookTitle);

    // generate library report 
    void generateReport() const;

    // friend classes
    friend class Book;
    friend class Member;
};

#endif // LIBRARY_H
