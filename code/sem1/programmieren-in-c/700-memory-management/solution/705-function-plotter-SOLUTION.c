/* Function_plotter.c
   This program uses pointers to functions, which are passed as arguments in function calls.

    TO DO 1: Have a look at the program and see how function pointers are used.
    TO DO 2: Extend the draw_function such that the range for x and y can by passed: 
			 Define a struct range, which provides values for min, max and step.
    TO DO 3: Extend the draw_function, such that two functions 
             can be passed to the draw function and are shown in the same diagram.
			 Use a NULL pointer to indicate that there is no second function to display.
    TO DO 4: Optional: Add more functions and a menu to flexibly choose
	         which functions to show (use two function pointers).
*/

#include <math.h>
#include <stdio.h>

struct range {
	double min;
	double max;
	double step;
};

// Display function 
void draw_function(double (*f)(double), double (*g)(double), struct range *xrange, struct range *yrange)
{
   double x, y; 
   char fg;
   
   for(y=yrange->max; y>=yrange->min; y-=yrange->step) {
      for(x=xrange->min; x<=xrange->max; x+=xrange->step) {
		  fg=((*f)(x)>=y && f(x)<y+yrange->step);     // (*f)(....) or f(...) - both do the same
		  fg=(g!=NULL && (*g)(x)>=y && (*g)(x)<y+yrange->step)? (fg?'$': '|'): (fg? 'S':' ');
		  // Dereferencing *-operator is optional:
		  // f(x) and g(x) would also work
          printf("%c", fg);
      }
	  printf("\n");
   }
}

// Mathematical function to be displayed 
double my_function1(double x)
{
     return 1.2*sin(x);
}

double my_function2(double x)
{
     return x/8.;
}

int main()
{
     double (*fn_ptr1)(double);     // Defines a variable pointing to a function
	struct range xrange = { -10, 10, 0.2 };
	struct range yrange = { -1.5, 1.5, 0.1 };

     fn_ptr1=my_function1;  // Use additional pointer variable to show principle (not really necessary here)
     draw_function(fn_ptr1, my_function2, &xrange, &yrange); 

	getchar();
}
