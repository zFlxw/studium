// Switch case: Order your burger...
// TO DO 1: Replace the if-statements with switch case and add a default case
// for invalid input TO DO 2: Add support for extra-large and fish burgers TO DO
// 3: Extend the program such that is executed in a loop, which can be aborted
// by entering 'q' as size TO DO 4: If there is a much longer list of options:
// How can long if-else-chains / switch-case-statements be avoided? TO DO 5:
// Optional: Any further ideas for additional sizes and options?

#include <stdio.h>

int main() {
  char size, specials;
  int height;
  float price;
  int abort = 0;

  while (1) {
    printf(
        "Which size you want your burger (s=small, m=medium, l=large, "
        "x=extra-large)? Type 'q' to quit the ordering process.");
    scanf(" %c", &size);
    if ((size | 32) == 'q') {
      break;
    }

    printf("Any specials (r=regular: beef, v=veggie, c=cheese)?");
    scanf(" %c", &specials);

    switch (size) {
      case 's':
        height = 1;
        price = 2.5f;
        break;

      case 'm':
        height = 2;
        price = 3.5f;
        break;

      case 'l':
        height = 3;
        price = 4.5f;
        break;

      case 'x':
        height = 5;
        price = 7.5f;
        break;

      default:
        height = 1;
        price = 2.5f;
    }

    printf("\n\n.-\"\"\"\"-.\n");
    while (height--) {
      switch (specials) {
        case 'v':
          printf("(vvvvvv)\n");
          break;

        case 'f':
          printf("(ffffff)\n");
          break;

        case 'c':
          printf(" ------ \n");

        default:
          printf("(mmmmmm)\n");
      }
    }
    printf("\\______/\n");
    printf("\n\n%.2f Euro - Enjoy!", price);
  }

  return 0;
}