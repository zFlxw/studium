#include <stdio.h>

void while_l() {
  int i = 0;
  while (i < 10) {
    // ...
    i++;
  }


  do {
    if (i >= 10) {
        break;
    }
    // ...
    i++;
  } while (i < 10);
}

int main() {

  char name[20];
  char str[] = "wie gehts?";
  char text[] = "Hallo";

  scanf("%19[^\n]", name);
  printf("%s, %s, %s", text, name, str);
}
