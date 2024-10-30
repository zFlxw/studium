/* Compare two strings */
// TO DO 1: This program does not always give the correct results. What is the
// problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used
// for providing an ordering e.g. for phone books

#include <stdio.h>
#include <string.h>

void compareStrings() {
  char s1[100], s2[100];
  int i, flag;

  printf("Please enter string 1:\n");
  fgets(s1, 100, stdin);
  s1[strcspn(s1, "\n")] = '\0';

  printf("Please enter string 2:\n");
  fgets(s2, 100, stdin);
  s2[strcspn(s2, "\n")] = '\0';

  flag = 0;
  i = 0;
  while (s1[i] != 0 && s2[i] != 0) {
    if (s1[i] != s2[i]) {
      flag = 1;
    }

    i += 1;
  }

  if (flag) {
    printf("Strings are different\n");
  } else {
    printf("Strings are equal\n");
  }
}

int orderStrings() {
  char s1[100], s2[100];
  int i, flag;

  printf("Please enter string 1:\n");
  fgets(s1, 100, stdin);
  s1[strcspn(s1, "\n")] = '\0';

  printf("Please enter string 2:\n");
  fgets(s2, 100, stdin);
  s2[strcspn(s2, "\n")] = '\0';

  flag = 0;
  i = 0;
  while (s1[i] == s2[i]) {
    i++;
  }

  flag = s1[i] < s2[i];

  if (flag) {
    printf("String one comes first\n");
  } else {
    printf("String two comes first\n");
  }
}

int main() {
  //compareStrings();
  orderStrings();
}