/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the first free position, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>


struct person
{
   char first_name[30];
   char last_name[30];
};

struct person students[100];

 

int main()
{



}