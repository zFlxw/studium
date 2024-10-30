/* Compare two strings */
// TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdio.h>

int main()
{
   char s1[100], s2[100];
   int i, flag;

   printf("Please enter string 1:\n");
   gets(s1);
   printf("Please enter string 2:\n");
   gets(s2);

   flag=0; i=0;
   while(s1[i]!=0)
   {
      if(s1[i]!=s2[i])
         flag=1;
      i=i+1;
   }
   if(flag)
      printf("Strings are different\n");
   else
      printf("Strings are equal\n");
}