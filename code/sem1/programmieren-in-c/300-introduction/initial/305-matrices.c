/* matrices */
// TO DO 1: Extend the programm such that the result is printed
// TO DO 2: Extend the programm such that it also calculates the product of the two 3x3 matrices.
// TO DO 3: What happens when you make a mistake with the indices, e.g. read/write m1[3][0], m1[4][0], m1[0][4] etc.? 

#include <stdio.h>

int main()
{
   float m1[3][3]= { { 12, 5.3, 10.0 }, { 5, 10.2, -2 },  { 1, -1, 3 } };
   float m2[3][3]= { { 2.1, -3, 1.5 },  { 10, -12, 3.1 }, { 4, 8.2, -2 } };
   float sum[3][3];

   int i, j;

   for(i=0; i<3; i=i+1)
      for(j=0; j<3; j=j+1)
         sum[i][j]=m1[i][j]+m2[i][j];
   
   // TO DO 1: Need to add output
   // Use e.g. format string %6.2f rather than just %f
}