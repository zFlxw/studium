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

int main() {
  int x = 10;
  int y = 20;

  printf("x + y = %d\n", add(x, y));
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  increase(&x);
  increase(&x);
  increase(&x);
  printf("x = %d\n", x);
  printf("y = %d\n", y);
}