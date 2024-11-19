// Ackermann: calculate the Ackermann function
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to
// the definition above
//          Test the program with very small values first!
//
// TO DO 2: Extend the function such that it counts the number of functions
// calls (use a global variable counter)
//          Print the function arguments and current count every x function
//          calls.
//
// TO DO 3: Count the amount of recursively called functions (which are not yet
// completed) and print them as well
//
// TO DO 4: Use static variables in ackermann for counting rather than global
// variables.
//
// TO DO 5: Optional: Visualize the current recursion depth with bars of
// ascii-characters: xxxxxxxxxxxxxxxxxx
//
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of
//          intermediate results

#include <stdio.h>

int calls;

int ackermann(int m, int n) {
  static int depth = 0;
  calls++;

  printf("Recursion depth: ");
  for (int i = 0; i < depth; i++) {
    printf("x");
  }
  printf("\n");

  if (m == 0) {
    depth--;
    return n + 1;
  }

  if (m > 0 && n == 0) {
    depth++;
    return ackermann(m - 1, 1);
  }

  if (m > 0 && n > 0) {
    depth++;
    return ackermann(m - 1, ackermann(m, n - 1));
  }

  depth--;
}

int main() {
  int n, m, result;
  calls = 0;

  printf("Value for m: ");
  scanf("%d", &m);
  printf("Value for n: ");
  scanf("%d", &n);

  // TO DO: Call ackermann function
  printf("Ackermann value: %d\n", ackermann(m, n));
  printf("Required calls: %d\n", calls);
}