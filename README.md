# Quick Connect – Contact Management System

> A simple command-line based contact management tool developed in C.

## 📌 Project Overview

Quick Connect is a mini project developed as part of the CO253: C Programming course. This program serves as a basic Contact Management System, allowing users to manage personal or professional contacts directly from a terminal interface.

The project was completed on **9th June 2023** as per the course requirements, though it is being committed to this repository in 2025 for archiving and reference purposes.

---

## 🛠️ Features

The system allows you to perform the following operations:

- ✅ **Add a new contact**
- 📋 **List all saved contacts**
- 🔍 **Search contacts by name or phone number**
- ❌ **Delete a contact**

Each contact holds the following details:
- Name
- Phone number
- Address
- Email

> ⚠️ Note: This is a **volatile system**, meaning the data will not persist after the program terminates. No files or databases are used to store the contact data.

---

## 🧱 Implementation Details

- Developed using **C programming language**
- Contact information is stored using an **array of structures**
- UI is entirely **command-line based**
- Modular code structure: Each operation (Add, List, Search, Delete) is implemented as a separate function
- Uses `typedef struct` to define a contact:
  ```c
  typedef struct {
      int phone;
      char name[20];
      char address[50];
      char email[30];
  } contact_t;



Sample UI
-------------QUICK CONNECT--------------
1. Add Contact
2. List Contacts
3. Search Contact by Name
4. Search Contact by Phone
5. Delete Contact
6. Exit
Enter your choice:


🧑‍💻 Developer Notes
The program uses a static array for storing contacts. No dynamic memory or external libraries are involved.
Code is documented with in-line comments to explain logic and improve readability.
Built and tested using GCC on a Linux-based environment.


📅 Timeline
Course: CO253 – C Programming (Mini Project)
Completed On: 9th June 2023
Repository Commit Date: 2025
