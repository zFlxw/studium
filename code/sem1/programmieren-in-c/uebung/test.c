#include <stdio.h>

int main() {
  for (int i = 1; i <= 6; i++) {
    int k = 0;
    for (int j = 0; j < 50; j++) {
      if (i == 0 || j % i == 0) {
        printf("%d", k % 10);
        k++;
      } else {
        printf("-");
      }
    }
    printf("\n");
  }
}