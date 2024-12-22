#include <stdlib.h>
#include <stdio.h>

void reserve(int n) {
  float *values = malloc(n * sizeof(float));
  if (values == NULL) {
    return;
  }

  for (int i = 0; i < n; i++) {
    *(values+i) = 2.0 * i;

    printf("%p\n", values+i);
    printf("%f\n", 2.0 * i);
  }

  free(values);
}

int main() {
  reserve(10);
}
