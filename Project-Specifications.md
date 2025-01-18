# Library Management System

## Project Overview

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


## Criteria and Requirements

### Number of Books
You need to write software that allows you to have a large number of books (think 10's of 1000's). Memory optimization will be important so you don't run out of memory. 

**Functions:** 
All the functions listed above, for each feature, must be implemented. Think about whether you want to implement them as methods of classes, or as separate functions. 

### Initial Setup
The initial data will be read in from a file. The data file will help you decide what attributes each book will have, but attributes for the other classes in the system will be left up to you. 

- **Operational Modes**:
How innovative you become with your system is left up to you. A minimal effort will result in a minimal grade. Think about happy-path and edge cases when you write your system. What happens, for instance, if someone tries to delete a book that is checked out. 



### Conclusion and Analysis

- As part of the reporting requirement, you will want to list things like :
  	How many books are in the system.
  	How many books are checked out.
  	How many books were added.
  	How many books were deleted.
  	Fees collected
  	Anything you believe is beneficial. Remember, the more minimal the system, the lower the grade


Your project will be evaluated based on how well you've implemented the following Object-Oriented Programming concepts and programming best practices:

1. **Object-Oriented Design:**
    - Your program must be designed around the principles of Object-Oriented Programming. Classes should be used to represent different entities where appropriate.
2. **Use of Dynamic Memory:**
    - Proper use of dynamic memory allocation (using `new` and `delete`) is expected, especially for managing collections of objects.
3. **Class Structures:**
    - Demonstrate understanding of class structures, including attributes, methods, and access specifiers (public, protected, private).
4. **Inheritance and Polymorphism:**
    - Your design should include examples of inheritance, showcasing the relationship between base and derived classes. Polymorphism should be used to allow for dynamic method binding.
5. **Encapsulation and Abstraction:**
    - Encapsulation should be evident through the use of classes to hide implementation details. Abstraction should be used to provide interfaces for classes, making the implementation details irrelevant to the user.
6. **Proper Use of Containers:**
    - Use C++ Standard Library containers (e.g., vectors, lists) to manage collections of objects efficiently.
7. **File Organization:**
    - Code should be well-organized across multiple files, typically separating class declarations in header files (.h) and definitions in implementation files (.cpp).
8. **Macro Guards in Header Files:**
    - Header files should contain macro guards to prevent multiple inclusions.
9. **Code Formatting:**
    - Your code should be well-formatted, using consistent indentation and whitespace to enhance readability.
10. **Efficient Memory Use:**
    - Demonstrate efficient memory use, avoiding memory leaks by properly deallocating dynamically allocated memory.
11. **Use of `const` and Pass-by-Reference:**
    - Where appropriate, use `const` to prevent modification of parameters passed to functions. Utilize pass-by-reference to avoid unnecessary copying of complex objects.
12. **Function Overloading and Default Arguments:**
    - Use function overloading to create functions with the same name but different parameters. Default arguments can be used to provide default values for function parameters.
13. **Error Handling:**
    - Implement error handling to manage unexpected situations or input errors gracefully.
14. **Documentation:**
    - Your code should be well-documented, including comments explaining the purpose of classes and methods, and any complex logic.

## Submission Instructions

To ensure a smooth submission and review process, please adhere to the following guidelines:

1. **Project Submission:**
    - Commit and push your complete project to your assigned GitHub Classroom repository.
2. **File Initialization**: You must include at least 3 files that can be used to load your system from files. The formatting of the initial data file will be given to you. You must include a guide in the README.md documentation.
3. **Documentation:**
    - Alongside your code, include a README.md within your repository. Repository READMEs are written in Markdown, the standard document writing language for code repositories that controls formatting mostly through typing, rather than a toolbar. Here is a page that gives an overview of the formatting commands: [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
    - This README.md should be at the top level of your repo and include at least the following sections.
        - **Compilation Instructions:** Detailed steps on how to compile your project, including any required flags or commands.
        - **Execution Instructions:** Clear instructions on how to run your project, specifying any required arguments or inputs.
        - **Project Status:** An overview of the current state of your project, highlighting whether it is complete, any known bugs, or incomplete features.
        - **Manual**: Include a brief, yet informative instruction manual telling users how to interact with your program and what it does. Include a brief description of your code design and how you went about implementing the project. Assume the reader is not familiar with the project before reading your manual.
        - **UML Diagrams**: Include UML diagrams for all of your classes. We recommend using [Mermaid](https://mermaid.live) , a convenient tool for building charts using a code-like syntax. You can embed the Mermaid code directly into your .md file using a markdown code block (open with \`\`\`mermaid and end the block with \`\`\`) and the code will render into the diagram. Think of the backticks like curly braces bundling the UML code together.
	        - [Mermaid Cheat Sheet](https://mermaid.js.org/syntax/classDiagram.html)
		    You may use whatever tool you like to make the UML Diagrams (like another online tool, or any tool that lets you make tables, like Excel \[Free for you with your student email])
		    Include the UMLs either embedded into your `README.md `or in their own `UML.pdf` file. Your choice.
 4. **Compatibility:**
    - Your project must be fully functional within GitHub Codespaces. This is crucial for ensuring that your project can be run and evaluated in a standardized environment.
    - You can still develop locally, but you should still ensure your code behaves as expected within a Codespace before committing.
