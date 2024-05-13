# PreTriage Application

This application is designed to assist in the pre-triage process at a healthcare facility. It manages the registration, admission, and lineup of patients, categorizing them based on their condition and urgency.


## Table of Contents
- [Overview](#overview)
- [Encapsulation, Inheritance, and Polymorphism](#encapsulation-inheritance-and-polymorphism)
- [Compilation and Execution](#compilation-and-execution)
- [Usage](#usage)

<br />

## Overview
The PreTriage application consists of several modules that handle different aspects of the pre-triage process. Here's a brief overview of each module:
- **PreTriage**: Manages the overall flow of the pre-triage process, including registration, admission, and lineup management.
- **Patient**: Represents a patient with relevant information such as name, OHIP number, arrival time, and symptoms.
- **TestPatient**: Inherits from Patient and represents a `patient` requiring a contagion test.
- **TriagePatient**: Inherits from `Patient` and represents a patient requiring triage assessment.
- **Ticket**: Represents a ticket assigned to a patient, containing information such as arrival time and OHIP number.
- **Time**: Represents time in hours and minutes.
- **IOAble**: Provides input and output functionalities for objects.
- **Menu**: Provides a menu interface for user interaction.
- **Utils**: Contains utility functions used throughout the application.
- **App-TestX.cpp**: Test applications to evaluate different scenarios of the pre-triage process.

<br />

## Encapsulation, Inheritance, and Polymorphism
The PreTriage application demonstrates the use of encapsulation, inheritance, and polymorphism to achieve modularity and extensibility.

### Encapsulation
1. Classes: Each entity in the application, such as `Patient`, `Ticket`, and `Time`, is encapsulated within a class, keeping their data and methods together and hiding their internal details.
2. Data Hiding: All class members are  declared as private to hide implementation details and provide controlled access through public member functions.
3. Access Control: The application uses access specifiers (`public`, `private`) to control the visibility of class members, ensuring that only relevant functionality is exposed.

### Inheritance
1. Base Class: The `Patient` class serves as a base class for different types of patients, such as `TestPatient` and `TriagePatient`.
2. Derived Classes: Subclasses like `TestPatient` and `TriagePatient` inherit common attributes and behaviors from the `Patient` class while extending or modifying them as necessary.
3. Code Reuse: Inheritance allows the application to reuse code implemented in the base class, reducing redundancy and promoting maintainability.

### Polymorphism
1. Virtual Functions: The `IOAble` class declares pure virtual functions `read` and `write`, which must be implemented by derived classes.
2. Derived Classes: Classes like `Patient` and `Ticket` derive from IOAble to indicate that they support input and output operations.
3. Polymorphic Behavior: Pointers or references of type `IOAble` can be used to interact with objects of derived classes, allowing for polymorphic behavior during input/output operations.

<br />

## Compilation and Execution
To compile the application, you can use any standard C++ compiler. Here's a general compilation command:
```bash
g++ -std=c++11 -Wall -o main PreTriage.cpp Patient.cpp TestPatient.cpp TriagePatient.cpp Ticket.cpp Time.cpp IOAble.cpp Menu.cpp Utils.cpp
```
To execute the application, run the compiled executable:
```bash
./main
```

<br />

## Usage
Upon running the application, users are presented with a menu interface where they can perform the following actions:

1. Register a patient
2. Admit a patient
3. View the lineup

Users can select an option by entering the corresponding number. Each action is explained within the application.

<br />

## Sample Data Files
Sample CSV data files (`smalldata.csv` and `bigdata.csv`) are provided to simulate patient records for testing the application. These files contain patient information such as arrival time, name, OHIP number, and symptoms.
