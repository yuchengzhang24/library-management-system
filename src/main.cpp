/*******************************************************
Name       :  Yucheng Zhang
Class      :  CSCI 2312 Section 002
Assignment :  Project 1: Library Management System
Due Date   :  11/29/2024
*******************************************************/

#include "Book.h"
#include "Audiobook.h"
#include "Library.h"
#include "Member.h"

#include <iostream>

using namespace std;

int main() {
  Library library;

  cout << "\nWelcome to the Library! Press Enter to continue...";
  cin.ignore();
  
  library.readBooksFromFile("data/books.txt");
  library.readMembersFromFile("data/members.txt");
  cout << "\nBook and Member information successfully loaded into system. Press Enter to continue...";
  cin.ignore();
  cout << endl;

  int choice;
  while (true){
    cout << "=====================================================================================" << endl
         << "Enter corresponding number to perform one of the following actions, or -1 to stop." << endl
         << " '1' : Display library catalog." << endl
         << " '2' : Display member catalog." << endl
         << " '3' : Perform a book checkout." << endl
         << " '4' : Perform a book return." << endl
         << " '5' : Add a book to the library." << endl
         << " '6' : Remove a book from the library." << endl
         << " '7' : Add a member to the library." << endl
         << " '8' : Remove a member from the library." << endl
         << " '9' : Generate a report of the library." << endl
         << " '10' : Simulate functions (For Ease of Grading)." << endl
         << "=====================================================================================" << endl;
    
    cout << "\n Choose an operation: ";
    cin >> choice;
    if (choice == -1) break;
    string memberID;
    string bookTitle;
    switch (choice) {
      case 1:
        library.displayBooks();
        break;
      case 2:
        library.displayMembers();
        break;
      case 3:
        cout << "\nEnter the title of the book you'd like to check out: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "\nEnter the member ID for the member you'd like to check this book out to: ";
        getline(cin, memberID);
        library.checkOutBook(memberID, bookTitle);
        break;
      case 4:
        cout << "\nEnter the title of the book you'd like to return: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "\nEnter the member ID for the member you'd like to return this book from: ";
        getline(cin, memberID);
        library.returnBook(memberID, bookTitle);
        break;
      case 5:
        cin.ignore();
        library.addBook();
        break;
      case 6:
        cin.ignore();
        library.removeBook();
        break;
      case 7:
        cout << "\n Add a member starting from Member ID 021, incrementing by 1 for each new member added." << endl;
        cin.ignore();
        library.addMember();
        break;
      case 8:
        cin.ignore();
        library.removeMember();
        break;
      case 9:
        cin.ignore();
        library.generateReport();
        break;
      case 10:
        cout << "\nRunning Simulation..." << endl;
        
        // simulate adding members and books. 
        cout << "\nAdd a member with member ID starting at 021 and increment by 1 for each new member." << endl;
        cin.ignore();
        library.addMember();
        library.addMember();
        library.addBook();
        library.addBook();
        
        // simulate book checkout and book return
        library.checkOutBook("001", "Jane Eyre");
        library.checkOutBook("001", "Brave New World");
        library.checkOutBook("002", "1984");
        library.checkOutBook("003", "Fahrenheit 451");
        library.checkOutBook("003", "The Odyssey");
        library.checkOutBook("004", "Dracula");
        library.checkOutBook("004", "Frankenstein");
        library.checkOutBook("005", "The Jungle");
        library.checkOutBook("020", "The Night Manager");
        library.checkOutBook("019", "The Whisper Man");
        library.checkOutBook("018", "The Couple Next Door");
        library.checkOutBook("017", "Circe");
        library.returnBook("001", "Jane Eyre");
        library.returnBook("003", "Fahrenheit 451");

        // simulate book checkout for added members 
        library.checkOutBook("021", "It");
        library.checkOutBook("021", "The Shining");
        library.checkOutBook("022", "The Hunger Games");

        // simulate errors 
        library.checkOutBook("005", "1984");
        library.returnBook("005", "Brave New World");

        // simulate deleting members and books. 
        library.removeMember();
        library.removeBook();

        library.displayBooks();
        library.displayMembers();
        library.generateReport();

      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }
  return 0;
}
