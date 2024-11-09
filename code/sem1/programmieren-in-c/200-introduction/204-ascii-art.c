/* ascii_art.c */
/* TO DO 1: Can you explain why a circle is displayed?
   TO DO 2: Play around with the operators to create beautiful ascii art
            - use different arithmetics
            - use different comparisons
            - use different characters (e.g. more than two) */

#include <stdio.h>
#include <math.h>

int main()
{
   int x, y, v;

   for (y = 0; y < 30; y = y + 1)
   {
      for (x = 0; x < 30; x = x + 1)
      {
         v = (x - 25) * (x - 15) + (y - 15) * (y - 15);
         if (v > 60 || v < sqrt(60))
            printf(" ");
         else
            printf("o");
      }
      printf("\n");
   }
}
