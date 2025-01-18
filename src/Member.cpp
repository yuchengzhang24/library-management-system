/*********************************************************
* Summary: This file defines all the methods declared in   
*          Member.h for Project 1: Library Management System
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
#include "Book.h"
#include "Member.h"

using namespace std;

// default constructor 
Member::Member()
      : memberID(""), name(""), email("") {}

// fully parametized constructor 
Member::Member(const string& aMemberID, const string& aName, const string& aEmail)
      : memberID(aMemberID), name(aName), email(aEmail) {}

// getters 
string Member::getMemberID() const{
  return memberID;
}
string Member::getName() const{
  return name;
}
string Member::getEmail() const{
  return email;
}
vector<Book*> Member::getCheckedOutBooks() const{
  return checkedOutBooks;
}

// setters 
void Member::setMemberID(const string& newMemberID){
  memberID = newMemberID;
}
void Member::setName(const string& newName){
  name = newName;
}
void Member::setEmail(const string& newEmail){
  email = newEmail;
}
void Member::setLateFeePerDay(double newFee){
  lateFeePerDay = newFee;
}

// set the due date for a book
void Member::setDueDate(Book* book, int days){
  time_t now = time(nullptr);
  // convert to seconds
  dueDates[book] = now + (days * 24 * 60 * 60);
}

// check if book is overdue (code adapted from online resources)
bool Member::isBookOverdue(Book* book) const{
  // search for book in dueDates map and check if the book has a due date
  auto it = dueDates.find(book);
  if (it != dueDates.end()){
    // compares current time with stored due date, return true if book is overdue
    return std::time(nullptr) > it->second;
  }
  else{
    return false;
  }
}

// calculate late fee for book
double Member::calculateLateFee(Book* book) const{
  if (isBookOverdue(book)){
    // calculate difference in time between check out and due in seconds
    double overdueDays = difftime(time(nullptr), dueDates.at(book)) / (60 * 60 * 24);
    return ceil(overdueDays) * lateFeePerDay;
  }
  else{
    return 0.0;
  }
}

// borrow a book
void Member::borrowBook(Book* book){
  // check if book is checked out
  if (!book->getAvailable()){
    throw "Error: Book is already checked out.";
  }
  // set availability to false (check out book)
  book->setAvailable(false);
  checkedOutBooks.push_back(book);
  // set a due date of 14 days
  setDueDate(book, 14);
  cout << "  Due on: " << ctime(&dueDates[book]);
}

// return a book (lambda function code adapted from online forum)
void Member::returnBook(const string& bookTitle){
  // search through checked out books list and find the book by title
  auto it = find_if(checkedOutBooks.begin(), checkedOutBooks.end(), [&](Book* book){
    return book->getTitle() == bookTitle;
  });

  // if book is found in the list, run calculateLateFee method on book and mark as available (returned)
  if (it != checkedOutBooks.end()){
    double lateFee = calculateLateFee(*it);
    (*it)->setAvailable(true);
    // remove book from due dates map
    dueDates.erase(*it);
    // remove book from checked-out books vector
    checkedOutBooks.erase(it);

    if(lateFee > 0){
      cout << "Late fee due: $" << lateFee << endl;
    }
    else{
      cout << "  Returned on time. No late fees accrued." << endl;
    }
  } 
  else{
    throw "Error: Book not found in the member's checked-out list.";
  }
}

// display member information 
ostream& operator<<(ostream& os, const Member& member){
  os << "---------------------------------------------------" << endl
     << setw(20) << left << "Member ID" << ":" << setw(30) << right << member.getMemberID() << endl
     << setw(20) << left << "Name" << ":" << setw(30) << right << member.getName() << endl
     << setw(20) << left << "Email" << ":" << setw(30) << right << member.getEmail() << endl
     << setw(20) << left << "Checked Out Books" << ":";
    if (member.checkedOutBooks.empty()){
      os << setw(30) << right << "None";
    }
    else{
      for (Book* book : member.checkedOutBooks){
        os << "\n - " << setw(20) << left << book->getTitle();

        auto it = member.dueDates.find(book);
        if (it != member.dueDates.end()){
          time_t dueDate = it->second;
          // display time im Y-M-D H:M:S format (code adapted from online resource)
          os << setw(18) << right << "Due: " << put_time(localtime(&dueDate), "%Y-%m-%d");
        }
      }
    }
  
  os << "\n---------------------------------------------------" << endl;
  return os;
}

// input member information 
istream& operator>>(istream& is, Member& member){
  string memberID, name, email;

  cout << endl;

  cout << "Enter Member ID: ";
  getline(is, memberID);
  member.setMemberID(memberID);

  cout << "Enter Name: ";
  getline(is, name);
  member.setName(name); 

  cout << "Enter Email: ";
  getline(is, email);
  member.setEmail(email);

  cout << "Member: " << name << " with Member ID: " << memberID << " successfully added." << endl;
  
  cout << endl;

  return is;
}