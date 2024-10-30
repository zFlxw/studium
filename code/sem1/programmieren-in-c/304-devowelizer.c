/* devowelizer / revowelizer
 TO DO 1: Extend the program such that it replaces all vowels in the text with
 other vowels. TO DO 2: Extend the program such that the replacement vowel is
 chosen randomly. Hint: List the vowels in an additional array ... Use rand() to
 generate random numbers TO DO 3: Modify the program such that it removes all
 vowels (and shortens the text accordingly) TO DO 4 (optional): Write an
 encryption/decryption program which encodes texts by defining in a table how
 each character shall be replaced by another one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void replaceRandomly(char txt[], char vowels[]) {
  int i = 0;
  while (txt[i] != 0) {
    for (int j = 0; j < 5; j++) {
      if (txt[i] == vowels[j]) {
        txt[i] = vowels[rand() % 5];
      }
    }
    i += 1;
  }

  printf("Replacement: %s", txt);
}

void removeVowels(char txt[], char vowels[]) {
  int i = 0;
  while (txt[i] != 0) {
    for (int j = 0; j < 5; j++) {
      if (txt[i] == vowels[j]) {
        for (int k = i; txt[k] != 0; k++) {
          txt[k] = txt[k + 1];
        }

        break;
      }
    }
    i += 1;
  }

  printf("Reduction: %s", txt);
}

int main() {
  char txt[1000];
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};

  srand(time(NULL));

  printf("Please enter your text:");
  fgets(txt, 1000, stdin);

  replaceRandomly(txt, vowels);
  removeVowels(txt, vowels);
}