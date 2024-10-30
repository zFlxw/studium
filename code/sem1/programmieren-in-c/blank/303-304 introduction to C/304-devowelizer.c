/* devowelizer / revowelizer 
 TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
 TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
          Hint: List the vowels in an additional array ...
                Use rand() to generate random numbers
 TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
         in a table how each character shall be replaced by another one. 
*/ 

#include <stdio.h>


int main()
{
   char txt[1000];
   int i;

   printf("Please enter your text:");
   gets(txt);

   i=0;
   while(txt[i]!=0)
   {
      // TO DO ....


      i=i+1;
   }
   printf("%s", txt);
}