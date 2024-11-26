/* address_list.c */
// This program should be completed such that it maintains a list of students
//
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter
// first name and last name and stores it at position i in the array.
//
// TO DO 2: Use a variable to count the number of students stored in the array.
//
// TO DO 3: Write a function printStudent(i), which prints student i stored in
// the array
//
// TO DO 4: Write functions addStudent(), for adding a student at the first free
// position, and printAllStudents() for printing all students stored.
//
// TO DO 5: Write a function menu(), which allows the user to select one of the
// actions
//            - add Student
//            - print all students
//            - quit program
//
// TO DO 6: Extend the student data and the corresponding functions with the
// gender male/female (using "enum").
//
// TO DO 7: Create a structure for handling dates (day, month, year) and use it
// for birth date, date of enrollment etc.
//
// TO DO 8: Extend the program such it also handles address information (street,
// number, zip-code and city).
//
// TO DO 9: optional: Add a function and menu item for deleting a selected
// student.
//
// TO DO 10: optional: Add a function to sort the data according to given
// criteria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define N 100

const char *gender_map[] = {"male", "female", "diverse"};

typedef enum gender { male, female, diverse } gender_e;

typedef struct date {
  char day;
  char month;
  int year;
} date_t;

struct person {
  char first_name[30];
  char last_name[30];
  gender_e gender;
  date_t birthday;
};

struct person students[N];

int student_count = 0;

void input_student(int i, char first_name[], char last_name[], gender_e gender, date_t birthday) {
  struct person student;
  strcpy(student.first_name, first_name);
  strcpy(student.last_name, last_name);
  student.gender = gender;
  student.birthday = birthday;

  students[i] = student;
  student_count++;
}

void add_student(char first_name[], char last_name[], gender_e gender, date_t birthday) {
  int i = 0;
  while (i < N) {
    if (strlen(students[i].first_name) != 0 ||
        strlen(students[i].last_name) != 0) {
      i++;
      continue;
    }

    input_student(i, first_name, last_name, gender, birthday);
    break;
  }
}

void print_student(int i) {
  struct person student = students[i];

  printf("Student ID: %d\n", i);
  printf("Gender: %s", student.gender);
  printf("Fist Name: %s\n", student.first_name);
  printf("Last Name: %s\n", student.last_name);
}

void print_students() {
  printf("List of students:\n");
  for (int i = 0; i < N; i++) {
    if (strlen(students[i].first_name) == 0 ||
        strlen(students[i].last_name) == 0) {
      continue;
    }
    printf("%d: %s %s (%s)\n", i, students[i].first_name, students[i].last_name, gender_map[students[i].gender]);
  }
}

int main() {
  while (1) {
    system("clear");
    printf("Student Administration\n");
    printf("Select one of the following sections:\n");
    printf("[0] List all students\n");
    printf("[1] Add student\n");
    printf("[2] Quit\n");

    system("/bin/stty raw"); // Sendet temporär alle keyinputs ans Terminal und wartet nicht auf "Enter"
    char c = getchar();
    system("/bin/stty cooked");
    system("clear");
    switch (c) {
      case '0':
        print_students();
        printf("---\n Press enter to navigate back");
        getchar();
        break;
      case '1':
        printf("First Name: ");
        char first_name[128], last_name[128];
        char gender;
        scanf("%s[^\n]", first_name);

        printf("\nLast Name: ");
        scanf("%s[^\n]", last_name);

        printf("\nGender (m/f/d): ");
        scanf("\n%c", &gender);

        gender_e g;
        switch (gender) {
          case 'm':
            g = male;
            break;
          case 'f':
            g = female;
            break;
          case 'd':
            g = diverse;
            break;
          default:
            printf("Invalid gender. Aborting process...");
            sleep(3);
            continue;
        }

        char birthday, birthmonth, birthyear;
        printf("\nBirthday: ");
        scanf("\n%c[^\n]", birthday);

        printf("\nBirthmonth: ");
        scanf("\n%c[^\n]", birthmonth);

        printf("\nBirthyear: ");
        scanf("\n%c[^\n]", birthyear);

        date_t birthday_date;
        birthday_date.day = birthday;
        birthday_date.month = birthmonth;
        birthday_date.year = birthyear;

        printf("\n");
        add_student(first_name, last_name, g, birthday_date);
        printf("Added student \"%s %s\"\n", first_name, last_name);
        printf("---\n Auto-redirect in 3 seconds\n");
        sleep(3);
        break;
      case '2':
        exit(1);
    }
  }
}