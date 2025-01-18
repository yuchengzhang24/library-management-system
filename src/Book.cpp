/*********************************************************
* Summary: This file defines all the methods declared in   
*          Book.h for Project 1: Library Management System
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

using namespace std;

// default constructor 
Book::Book() 
    : title(""), author(""), ISBN(""), genre(""), available(true), borrowedBy("") {}

// partially defined constructor 
Book::Book(const string& aTitle, const string& aAuthor, const string& aISBN, const string& aGenre) 
    : title(aTitle), author(aAuthor), ISBN(aISBN), genre(aGenre), available(true), borrowedBy("") {}

// fully parametized constructor 
Book::Book(const string& aTitle, const string& aAuthor, const string& aISBN, const string& aGenre, bool isAvailable, const string& borrower)
    : title(aTitle), author(aAuthor), ISBN(aISBN), genre(aGenre), available(isAvailable), borrowedBy(borrower){}

// getters 
string Book::getTitle() const{
  return title;
}
string Book::getAuthor() const{
  return author;
}
string Book::getISBN() const{
  return ISBN;
}
string Book::getGenre() const{
  return genre;
}
bool Book::getAvailable() const{
  return available;
}
string Book::getBorrowedby() const{
  return borrowedBy;
}

// setters 
void Book::setTitle(const string& newTitle){
  title = newTitle;
}
void Book::setAuthor(const string& newAuthor){
  author = newAuthor;
}
void Book::setISBN(const string& newISBN){
  ISBN = newISBN;
}
void Book::setGenre(const string& newGenre){
  genre = newGenre;
}
void Book::setAvailable(bool newAvailability){
  available = newAvailability;
}
void Book::setBorrowedBy(const string& newBorrower){
  borrowedBy = newBorrower;
}

// function to display book details
void Book::displayInfo() const {
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "ISBN: " << ISBN << endl;
  cout << "Genre: " << genre << endl;
}

// display book details 
ostream& operator<<(ostream& os, const Book& book){
  os << "---------------------------------------------------------------------------------------------------------" << endl
     << book.getTitle() << "  |  " << book.getAuthor() << "  |  " << book.getISBN() << "  |  "
     << book.getGenre() << "  |  " << (book.available ? "Available" : "Checked out") << endl
     << "---------------------------------------------------------------------------------------------------------" << endl;
  return os;
}

// input book information 
istream& operator>>(istream& is, Book& book){
  string title, author, ISBN, genre; 

  cout << endl;

  cout << "Enter Title: ";
  getline(is, title);
  book.setTitle(title);

  cout << "Enter Author: ";
  getline(is, author);
  book.setAuthor(author);

  cout << "Enter ISBN: ";
  getline(is, ISBN);
  book.setISBN(ISBN);

  cout << "Enter genre: ";
  getline(is, genre);
  book.setGenre(genre);

  cout << "\nBook: " << title << " successfully added." << endl;

  cout << endl;

  return is;
}