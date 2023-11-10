#C DBMS Application

This Database Management System (DBMS) application in C provides basic CRUD (Create, Read, Update, Delete) functionality. The program operates on a text file ("1.txt") to store and manage entries, each consisting of an ID, name, and college. The user is presented with a menu to choose operations such as creating a new entry, reading the entire database, updating an entry, and deleting an entry. The application ensures the integrity of the database by checking for duplicate IDs before adding new entries.

## Usage

To use the application, compile the "1.c" file and run the executable. Follow the on-screen prompts to interact with the DBMS.

```bash
# Compile the code
gcc 1.c -o dbms

# Run the application
./dbms
