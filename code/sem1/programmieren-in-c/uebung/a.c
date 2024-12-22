#include <stdio.h>

void summenzeichen(int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + i;
  }
}

int add(int a, int b) {
  a++;
  b++;
  return a + b;
}

int increase(int *a) {
  printf("%p\n", a);
  (*a)++;
  printf("Increased %d\n", a);
}

int bitstuff() {
  int a = 12;

  a = a / (int)1.2;
  printf("a = %d\n", a);

  a &= 7;
  printf("a = %d\n", a);

  a <<= 2;
  printf("a = %d\n", a);

  a = (~a) & 15;
  printf("a = %d\n", a);

  a = a / 2 * 4;
  printf("a = %d\n", a);

  a = a > 5 ? a / 2 : a * 2;
  printf("a = %d\n", a);
}

void aufgabe() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < j; k++) {
        printf("%d", (j + i) % 10);
      }
      if (j > 0 && j < 9) {
        printf("-");
      }
    }
    printf("\n");
  }
}

int main() {
  /* int x = 10;
  int y = 20;

  printf("x + y = %d\n", add(x, y));
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  increase(&x);
  increase(&x);
  increase(&x);
  printf("x = %d\n", x);
  printf("y = %d\n", y); */

  aufgabe();
}