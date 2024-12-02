// hanoi.c Towers of hanoi
// TO DO: Optional: Extend the programm such that it creates a graphical output of the disks on the three rods
//         introduce a function display(), which is called from hanoi()
//         Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_H 8
int stack[3][MAX_H+1], height[3];

void draw_stacks(int n)
{
	system("CLS");
	for(int h=MAX_H; h>=0; h--) {
		for(int s=0; s<3; s++)
			for(int i=-MAX_H; i<=MAX_H; i++)
				printf(h<height[s] && abs(i)<stack[s][h]? "A": " ");
		printf("\n");
	}
   for(int i=0; i<50000000; i++);   // Warteschleife
}

void hanoi(int n, int start, int goal, int helper)
{
   if(n>0) {
      hanoi(n-1,start,helper,goal);
      printf("move disk from %d to %d\n", start, goal);
	   stack[goal][height[goal]++]=stack[start][--height[start]];
	   draw_stacks(n);
      hanoi(n-1,helper,goal,start);
   }
}

int main() 
{
   int i, n;

   printf("How many disks? (1-%d)", MAX_H);
   scanf("%d", &n);
  
   for(i=0; i<n; i++)
	   stack[0][i]=n-i;
   height[0]=n;
   height[1]=height[2]=0;

   hanoi(n, 0, 1, 2);
   getchar();
}