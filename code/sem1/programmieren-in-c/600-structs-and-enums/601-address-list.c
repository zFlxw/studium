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
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define N 10

const char *gender_map[] = {"male", "female", "diverse"};

typedef enum gender { male, female, diverse } gender_e;

typedef struct date {
  unsigned int day;
  unsigned int month;
  unsigned int year;
} date_t;

typedef struct address {
  char street[128];
  int number;
  int zip;
  char city[128];
} address_t;

struct person {
  char first_name[30];
  char last_name[30];
  gender_e gender;
  date_t birthday;
  address_t address;
};

struct person students[N];

int student_count = 0;

void set_raw_mode() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);           // Get current terminal settings
  term.c_lflag &= ~(ICANON | ECHO);         // Disable canonical mode and echo
  tcsetattr(STDIN_FILENO, TCSANOW, &term);  // Apply settings immediately
}

void reset_terminal_mode() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ICANON | ECHO);  // Re-enable canonical mode and echo
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void input_student(int i, char first_name[], char last_name[], gender_e gender,
                   date_t birthday) {
  struct person student;
  strcpy(student.first_name, first_name);
  strcpy(student.last_name, last_name);
  student.gender = gender;
  student.birthday = birthday;

  students[i] = student;
  student_count++;
}

void add_student() {
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
      return;
  }

  printf("Enter the students birthday information.\n");
  unsigned int birthday, birthmonth, birthyear;
  printf("\nDay: ");
  scanf("%u", &birthday);

  printf("\nMonth: ");
  scanf("%u", &birthmonth);

  printf("\nYear: ");
  scanf("%u", &birthyear);

  date_t birthday_date;
  birthday_date.day = birthday;
  birthday_date.month = birthmonth;
  birthday_date.year = birthyear;

  printf("\n");

  char street_name[128];
  printf("Enter the students address information.\n");
  printf("Street Name: ");
  scanf("\n%128[^\n]", &street_name);

  printf("The street name is: '%s'", street_name);

  int i = 0;
  while (i < N) {
    if (students[i].first_name[0] != 0 || students[i].last_name[0] != 0) {
      i++;
      continue;
    }

    input_student(i, first_name, last_name, gender, birthday_date);
    break;
  }

  printf("Added student \"%s %s\"\n", first_name, last_name);
  printf("---\n Press Enter to navigate back.\n");

  int c;
  while ((c = getchar()) != '\n') {
  }  // Flusht den Input Buffer, da getchar() sonst das \n annimmt und geskippt
     // wird
  getchar();
}

void delete_student() {
  int current_id = 0;
  char c;

  set_raw_mode();
  while (1) {
    reset_terminal_mode();
    system("clear");
    printf("Select the student you want to delete:\n");
    for (int i = 0; i < N; i++) {
      if (students[i].first_name[0] == 0 || students[i].last_name[0] == 0) {
        continue;
      }

      struct person student = students[i];

      char prefix[4] = "   ";
      if (i == current_id) {
        strcpy(prefix, "[>]");
      }

      printf("%s %s %s\n", prefix, student.first_name, student.last_name);
    }

    set_raw_mode();
    c = getchar();
    if (c == '\033') {
      getchar();
      c = getchar();

      if (c == 'A') {
        current_id = current_id > 0 ? current_id - 1 : student_count;
      } else if (c == 'B') {
        current_id = current_id < student_count ? current_id + 1 : 0;
      }
    } else if (c == '\n') {
      break;
    }
  };
  reset_terminal_mode();

  printf("\nDelete user %d\n", current_id);
  for (int i = current_id; i < student_count - 1; i++) {
    students[i] = students[i + 1];
  }

  memset(&students[student_count - 1], 0, sizeof(struct person));
  student_count--;

  printf("Press Enter to navigate back.");
  while ((c = getchar()) != '\n');
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
    struct person student = students[i];
    if (strlen(student.first_name) == 0 || strlen(student.last_name) == 0 ||
        student.first_name[0] == 0 || student.last_name[0] == 0) {
      continue;
    }

    printf("%d: %s %s - %u.%u.%u - (%s)\n", i, student.first_name,
           student.last_name, student.birthday.day, student.birthday.month,
           student.birthday.year, gender_map[student.gender]);
  }
}

int main() {
  date_t date;
  date.day = 23;
  date.month = 1;
  date.year = 2005;
  input_student(0, "Maik", "Zimmerschied", male, date);
  input_student(1, "Test", "Test", female, date);
  input_student(2, "XYZ", "SFFWF", diverse, date);

  while (1) {
    system("clear");
    printf("Student Administration\n");
    printf("Select one of the following sections:\n");
    printf("[0] List all students\n");
    printf("[1] Add student\n");
    printf("[2] Delete student\n");
    printf("[3] Quit\n");

    set_raw_mode();
    char c = getchar();
    reset_terminal_mode();
    system("clear");
    switch (c) {
      case '0':
        print_students();
        printf("---\n Press enter to navigate back");
        getchar();
        break;
      case '1':
        add_student();
        break;

      case '2':
        delete_student();
        break;
      case '3':
        exit(1);
        break;
    }
  }
}