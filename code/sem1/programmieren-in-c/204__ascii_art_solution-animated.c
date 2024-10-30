/* ascii_table.c Draw a table of all asci characters */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int x, y, cnt; 
	int sizex=60, sizey=40;
	while(1) {  
		system("CLS");
		for(y = 0; y<sizey; y++) {
			cnt+=2;
			for(x = 0; x<sizex; x++) {
				int v = (x-sizex/2)*(x-sizex/2)+(y-sizey/2)*(y-sizey/2);
				if(v%100>cnt) printf(" ");
				else printf("%c",177);
			}
			printf("\n");
		}
		cnt-=sizey*2-2; cnt+=5;
		for(x=0; x<10000000; x++);
		if(cnt>100) cnt=0;
	}
}

