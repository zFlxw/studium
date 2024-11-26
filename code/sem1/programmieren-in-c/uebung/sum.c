#include <stdio.h>

int numbers[] = {10, 13, 5, 19, 24, 3, 5, 12, 77, 84, 37};

int sumFor() {
  int sum = 0;

  for (int i = 0; i < 11; i++) {
    sum += numbers[i];
  }

  return sum;
}

int sumWhile() {
  int sum = 0, i = 0;
  while (i < 11) {
    sum += numbers[i];
    i++;
  }

  return sum;
}

int sumRecursive(int index, int sum) {
  if (index < 11) {
    return sumRecursive(index + 1, sum + numbers[index]);
  }

  return sum;
}

int main() {
  printf("Sum (for): %d\n", sumFor());
  printf("Sum (while): %d\n", sumWhile());
  printf("Sum (recursive): %d\n", sumRecursive(0, 0));

  return 0; 
}
