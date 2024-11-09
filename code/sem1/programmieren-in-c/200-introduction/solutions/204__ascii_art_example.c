/* ascii_art.c */

#include <stdio.h>

int main() 
{
   int x, y; 
   int sizex=60, sizey=40;

   for(y = 0; y<sizey; y++) {
      for(x = 0; x<sizex; x++) {
	    int v = (x-sizex/2)*(x-sizex/2)+(y-sizey/2)*(y-sizey/2);
            if(v%100>40) printf(" ");
            else printf("%c",219);
      }
      printf("\n");
   }
   getchar();
}
