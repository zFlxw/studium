#include <stdio.h>

enum months { JANUARY = 1, MARCH = 3, AUGUST = 8, DECEMBER = 12 };
enum error_codes { NOT_FOUND = 405, NOT_ALLOWED = 403 };

struct user {
  int *id;
};

int add(int *a) {
  (*a)++;
}

int main() {
  int x = 10;
  printf("x=%d\n", x);
  add(&x);
  printf("x=%d\n", x);

  // web client -> server
  // server: status code 404

  struct user my_user;

  int error = 404;
  if (error == NOT_FOUND) {
    printf("Kein Zugriff\n");
  }

  int a = 5;
  float b = a;

  //...
  
  printf("March: %d\n", MARCH);
  printf("August: %d\n", AUGUST);
  printf("December: %d\n", DECEMBER);
}