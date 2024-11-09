/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>

int main() {

   char c, old_c;
   short s, old_s;
   int i, old_i;
   long l, old_l;

   c=0;

   while(1) {  // repeat the following code in { .... } endless
      old_c=c; // remember previous value
      c=c+1;   // increase c by 1, you may also use the short form: c++;
      if(old_c>c) { // execute the following code in { ... } if condition is true
	     printf("char  overflow %d -> %d \n", old_c, c);
      }
      // printf format strings:  
      // char, short, int: "%d"
      // long: "%ld"
      // unsigned int: "%u"
   }
}
