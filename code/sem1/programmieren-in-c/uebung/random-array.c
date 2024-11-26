/**
 * Aufgabe: Gegeben ist ein Array aus Ganzzahlen (0 <= n <= 9). Bilde aus den
 * gegebenen Zahlen die größtmögliche Zahl m.
 *
 * Beispiel:
 * numbers[] = {1, 2, 3}
 * m = 321
 */
int numbers[] = {5, 1, 6, 2, 4, 3};

#define N sizeof(numbers) / sizeof(numbers[0])

#include <stdio.h>

int power(int base, unsigned int exp) {
  int i, result = 1;
  for (i = 0; i < exp; i++) result *= base;
  return result;
}

void sort(int array[]) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (array[j] < array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  sort(numbers);
  int n = 0;
  for (int i = 0; i < N; i++) {
    printf("%d, ", numbers[i]);
    n += numbers[i] * power(10, N - i);
  }
  n /= 10;
  printf("%d\n", n);
}