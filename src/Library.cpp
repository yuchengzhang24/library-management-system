/*********************************************************
* Summary: This file defines all the methods declared in 
*          Library.h for Project 1: Library Management System
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
#include "Library.h"

using namespace std; 

// default constructor 
Library::Library() {}

// getters
vector<Book*>& Library::getBooks(){
  return books;
}
vector<Member*>& Library::getMembers(){
  return members;
}

// find a book by title
bool Library::findBook(const string& title) const{
  for (Book* book: books){
    if (book->getTitle() == title){
      return true;
    }
  }
  return false;
}

// get a book by title
Book* Library::getBookByTitle(const string& bookTitle) const {
  for (Book* book : books) {
    if (book->getTitle() == bookTitle) {
      // if book is found, return pointer to book object
      return book;
    }
  }
  // if not found, return nullptr
  return nullptr; 
}

// overloading the + operator for Book 
void operator+(vector<Book*>& books, Book* book){
    books.push_back(book);
}

// overloading the - operator for Book
void operator-(vector<Book*>& books, const string& bookTitle){
  for (int i = 0; i < books.size(); i++){
    if(books[i]->getTitle() == bookTitle){
      delete books[i];
      books.erase(books.begin() + i);
    }
  }
}

// add a book 
void Library::addBook(){
  Book* newBook = new Book();
  cin >> *newBook;

  if (findBook(newBook -> getTitle())){
      throw "Book already exists in the library.";
  }
  else{
      books + newBook;
      booksAdded++;
  }
}

// remove a book 
void Library::removeBook(){
    string bookTitle;
    cout << "\nEnter the title of the book you'd like to remove: ";
    getline(cin, bookTitle);

    if (findBook(bookTitle)){
      cout << endl;
      cout << bookTitle << " successfully removed from library.\n" << endl;
      books - bookTitle;
      booksRemoved++;
    }
    else{
        throw "Book not found.";
    }
}

// display books 
void Library::displayBooks() const{
  cout << "\nBooks in the Library: " << endl;
  for (Book* book: books){
    cout << *book << endl;
  }
}

// find a member by member ID
bool Library::findMember(const string& MemberID) const{
  for (Member* member: members){
    if (member->getMemberID() == MemberID){
      return true;
    }
  }
  return false;
}

// get a member by memberID
Member* Library::getMemberByID(const string& memberID) const{
  for (Member* member : members){
    if (member->getMemberID() == memberID){
      // if member is found, return pointer to member
      return member;
    }
  }
  // if member is not found, return nullptr
  return nullptr; 
}

// overloading the + operator for member 
void operator+(vector<Member*>& members, Member* member){
    members.push_back(member);
}

// overloading the - operator for member
void operator-(vector<Member*>& members, const string& memberID){
  for (int i = 0; i < members.size(); i++){
    if(members[i]->getMemberID() == memberID){
      delete members[i];
      members.erase(members.begin() + i);
    }
  }
}

// add a member
void Library::addMember(){
  Member* newMember = new Member();
  cin >> *newMember;

  if (findMember(newMember -> getMemberID())){
      throw "Member already registered in the library.";
  }
  else{
      members + newMember;
      membersAdded++;
  }
}

// remove a member 
void Library::removeMember(){
    string memberID;
    cout << "\nEnter the member ID of the member you'd like to remove: ";
    getline(cin, memberID);

    if (findMember(memberID)){
      cout << endl;
      cout << "Member with member ID: " << memberID << " successfully removed from library.\n" << endl;
      members - memberID;
      membersRemoved++;
    }
    else{
        throw "Member not found.";
    }
}

// display members 
void Library::displayMembers() const{
  cout << "\nMembers Registered in Library: " << endl;
  for (Member* member: members){
    cout << *member << endl;
  }
}

// read books from file into library
void Library::readBooksFromFile(const string& fileName){
  ifstream file(fileName);

  if (!file.is_open()){
    throw "Failed to open the file.";
  }

  string line;
  while(getline(file, line)){
    stringstream ss(line);
    string title, author, ISBN, genre;

    // parse book information
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, ISBN, ',');
    getline(ss, genre, ',');

    // create a new book with parsed information and add it to the library
    Book* newBook = new Book(title, author, ISBN, genre);
    books + newBook;
    ss.clear();
  }

  file.close();
}

// read books from file into library
void Library::readMembersFromFile(const string& fileName){
  ifstream file(fileName);

  if (!file.is_open()){
    throw "Failed to open the file.";
  }

  string line;
  while(getline(file, line)){
    stringstream ss(line);
    string memberID, name, email;

    // parse book information
    getline(ss, memberID, ',');
    getline(ss, name, ',');
    getline(ss, email, ',');

    // create a new book with parsed information and add it to the library
    Member* newMember = new Member(memberID, name, email);
    members + newMember;
    ss.clear();
  }

  file.close();
}

// takes a memberID and a book title and checks out the book
void Library::checkOutBook(const string& memberID, const string& bookTitle){
    // find the member by ID
    Member* member = getMemberByID(memberID); 
    if (member == nullptr){
        cout << endl;
        cout << "Error: Member with ID " << memberID << " not found.\n" << endl;
        return;
    }

    // find the book by title
    Book* book = getBookByTitle(bookTitle);
    if (book == nullptr){
        cout << endl;
        cout << "Error: Book with title '" << bookTitle << "' not found.\n" << endl;
        return;
    }

    // check if the book is available
    if (!book->getAvailable()){
        cout << endl;
        cout << "Error: The book '" << bookTitle << "' is already checked out.\n" << endl;
        return;
    }

    // check if the member has already checked out the book
    for (Book* checkedOutBook : member->getCheckedOutBooks()) {
        if (checkedOutBook->getTitle() == bookTitle) {
            cout << endl;
            cout << "Error: Member '" << member->getName() << "' has already checked out the book '" << bookTitle << "'.\n" << endl;
            return;
        }
    }

    cout << endl;
    cout << member->getName() << " successfully checked out '" << bookTitle << "'." << endl;
    // run borrowBook method in the member class
    member->borrowBook(book);
    cout << endl;
}

// takes a memberID and book title and returns the book
void Library::returnBook(const string& memberID, const string& bookTitle){
  //find the member by ID
  Member* member = getMemberByID(memberID); 
  if (member == nullptr){
    cout << endl;
    cout << "Error: Member with ID " << memberID << " not found.\n" << endl;
    return;
  }

  // find the book by title
  Book* book = getBookByTitle(bookTitle);
  if (book == nullptr){
    cout << endl;
    cout << "Error: Book with title '" << bookTitle << "' not found.\n" << endl;
    return;
  }

  // check if the book is checked out by the member
  bool found = false;
  for (Book* checkedOutBook : member->getCheckedOutBooks()){
    if (checkedOutBook->getTitle() == bookTitle){
      found = true;
      break;
    }
  }

  if (!found){
    cout << endl;
    cout << "Error: The book '" << bookTitle << "' is not checked out by member '" << member->getName() << "'.\n" << endl;
    return;
  }
  
  cout << endl;
  cout << member->getName() << " successfully returned '" << bookTitle << "'." << endl;
  // run returnBook method in the member class
  member->returnBook(bookTitle);
  cout << endl;
}

// generate a library report 
void Library::generateReport() const{
  int checkedOut = 0;
  for (Book* book: books){
    if (!book->getAvailable()){
      checkedOut++;
    }
  }

  int memberCheckCount = 0;
  for (Member* member: members){
    if (!member->getCheckedOutBooks().empty()){
      memberCheckCount++;
    }
  }

  cout << "\nLibrary Report: " << endl
       << "-----------------------------------" << endl
       << setw(25) << left << "Total Books" << ":" << setw(9) << right << books.size() << endl
       << setw(25) << left << "Books Checked Out" << ":" << setw(9) << right << checkedOut << endl
       << setw(25) << left << "Books Added" << ":" << setw(9) << right << booksAdded << endl
       << setw(25) << left << "Books Removed" << ":" << setw(9) << right << booksRemoved << endl
       << "-----------------------------------" << endl
       << setw(25) << left << "Total Members" << ":" << setw(9) << right << members.size() << endl
       << setw(25) << left << "Members Borrowing Books" << ":" << setw(9) << right << memberCheckCount << endl
       << setw(25) << left << "Members Added" << ":" << setw(9) << right << membersAdded << endl
       << setw(25) << left << "Members Removed" << ":" << setw(9) << right << membersRemoved << endl
       << "-----------------------------------\n" << endl;
}