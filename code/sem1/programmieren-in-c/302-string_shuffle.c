/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char name[100], c;
   int i, p1, p2;

   printf("Please enter your name:\n");
   fgets(name, 100, stdin);
   // Safer alternatives, with some issues -> lecture:
   // scanf("%99[^\n]", name);
   // fgets(name, 100, stdin);  // Read max. 99 chars + space for 0-byte

   for (i = 0; i < 10; i++)
   {
      p1 = rand() % strlen(name); // strlen counts the number of characters in the string
      p2 = rand() % strlen(name);

      c = name[p1];

      if (name[p1] == ' ' || name[p2] == ' ' || p1 == 1 || p2 == 1) {
         continue;
      }

      name[p1] = name[p2];
      name[p2] = c;

      printf("Hello %s\n", name);
   }
}