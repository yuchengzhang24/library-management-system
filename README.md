# library-management-system
Library management system in C++ to demonstrate proficiency in OOP concepts and the ability to write modular, maintainable, and scalable code. 

# **Read Me**

## Description
Develop a system to manage a library's operations.

## Features
- **User Management**: Add, update, delete, and search for users (students, teachers, etc.).
- **Book Management**: Add, update, delete, and search for books.
- **Borrow/Return System**: Track borrowed books, due dates, and handle returns.
- **Late Fees Calculation**: Calculate and track late fees.
- **Reporting**: Generate reports for borrowed books, late returns, etc.

## Concepts Covered
- Inheritance
- Polymorphism
- File handling
- Exception handling
- STL (Standard Template Library)
- Design patterns (such as Singleton for database connection)

*******************************************************
## **Compilation Instructions**

To compile the code, ensure you are in the /src level of the program and run the following code:

    g++ -o main main.cpp Audiobook.cpp Book.cpp Library.cpp Member.cpp

*******************************************************
## **Execution Instructions**

To execute this program, run the following command after compilation:

    ./main

Upon successful execution, you should be greeted with a "Welcome to the Library!" message and prompted to press Enter to continue into the program.
*******************************************************
## **User Manual**

- When the program is successfully executed, data from **books.txt**, **audiobooks.txt** and **members.txt** will be read into the program, initializing the Books and Members vectors for the library. 
  - If the data is not successfully read into the file, error message: "Failed to open the file" will be thrown.

- After the data is read into the program, a menu will be displayed with 10 options: 
   1) Display library catalog
   2) Display member catalog
   3) Perform book checkout
   4) Perform book return
   5) Add a book to the library
   6) Remove a book from the library
   7) Add a member to the library
   8) Remove a member from the library 
   9) Generate a report of the library
   10) Simulate functions
    
     *Option 10 is for ease of grading: the program automatically simulates all the functons listed above and ouputs all the results to the console for the grader -- if you don't want to manually run the program.*

 **IMPORTANT:** If you are manually running the program and you run the add member function, please use 021 as the first memberID and icrement by 1 for every additional added member. ie: 022, 023...

- User will be prompted to choose an option until they choose to terminate the program (-1).

- Each library member has an independent checked out book vector that stores a list of books that they've checked out, and the due date for each book. 
  - Each due date is automatically set to 14 days after the book is checked out. 
  - If a book is returned late, a late fee is automatically calculated upon book return at the rate of $1 for every day the book is late. 
  - This information can all be displayed in the "Display member catalog" option, alongside a member's ID, name, and email.
- The "Display library catalog" option will display every book in the library. This will display the book title, author, ISBN, genre, and availability. 
  - Each book is set to "Available" by default until checked out. 
  - When a book is checked out, the availability will be switched to "Checked out"

**EXCEPTION HANDLING**
- Here are the following ways the program handles errors and exceptions: 
  - If data files are not successfully opened and read into the program: "Failed to open the file"
  - If user attempts to add a book already in catalog: "Book already exists in library"
  - If user attemps to remove a book that doesn't exist in the catalog: "Book not found"
  - If user attempts to add a member already in catalog: "Member already registered in the library"
  - If user attempts to remove a member already in catalog: "Member not found"
  - If user attempts to check out or return a book to a user that doesn't exist: "Member with ID not found"
  - If user attempts to check out or return a book that isn't in the catalog: "Book with title not found"
  - If user attempts to check out a book that is checked out by someone else: "Book is already checked out"
  - If user attempts to check out a book that they've already checked out: "Member has already checked out the book"
  - If user attempts to return a book that they haven't checked out: "Book is not checked out by member"

**PROGRAM IMPLEMENTATION**

The program was implemented with encapsulation, polymorphism and inheritance in mind. The Library class holds both Member and Book objects as lists, while the Book object is a parent/base class for the Audiobook class. Each member contains information such as their name, ID and email and contains a list of books that they've checked out. Each book contains information such as when the book is due and the fee per day for each day the book is returned late. 

Each list interacts with one another. When a book is checked out and added to a member's checked out book list, the book's availability is changed in the library system. 

The generate report function keeps a record of all the transactions done through the library system. It will display:
  - Total amount of books in the library
  - Number of books checked out
  - Number of books added
  - Number of books removed
  - Total number of registered members
  - Number of members with books checked out
  - Number of members added
  - Number of members removed

***NOTE**: Some lines of code contained within this program have been adapted from online resources such as Stack Overflow and ChatGPT. Any coded adapted online is specified in the in-line comments of the code itself.*

*******************************************************
## **Project Status**

   The program runs successfully and the core componenets of the program are implemented and complete. 

### KNOWN BUGS ###

The program does not currently have any known bugs. 

### INCOMPLETE FEATURES ###

While the core functions of this program are complete, here are some things I'd like to add to the program in the future: 
- Handling more edge cases: 
  - removing a book that is currently checked out
  - removing a member that has books checked out, 
  - removing a member that has outstanding dues 
- Better implementation of the Audiobook class with more methods 
- While the program currently has a method to calculate late fees, it lacks the ability to track total amount of late fees due.
  - Add a total fees due for each member object 
  - Add the ability to pay off fines 
  - Create restrictions on checking out new books if number of late books is exceeded
- Add different types of member objects (VIP, Librarian, Student, etc)


*******************************************************
