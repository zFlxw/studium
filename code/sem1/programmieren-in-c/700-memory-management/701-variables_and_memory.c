/* Variables and memory
  have a look the variables in your previous programs, e.g. address_list.c

  TO DO 1: Use sizeof to determine how much memory different types require in
  memory.

  TO DO 2: Also consider arrays, structs, enums and unions.

  TO DO 3: Use & to determine the addresses of different variables in memory.

  TO DO 4: Can you see a difference of addresses for local and global variables?

  TO DO 5: How are variables sorted in memory (increasing or decreasing
  addresses)?

  TO DO 6: What about addresses of local variables in recursive functions (e.g.
  hanoi.c)?

  TO DO 7: Can you find int variables stored at uneven addresses? How do you
  judge the result?

  TO DO 8: What is the size of the following struct? Why? Can it be reduced?
*/

#include <stdio.h>

struct test {
  char a;
  int b;
  char c;
  int d;
};

enum directions { NORTH, EAST, SOUTH, WEST };

union flint {
  int a;
  float b;
};

union flouble {
  float a;
  double b;
}; 

struct test my_test;

int intArray[4];
struct test testArray[4];

union flint var1;
union flouble var2;

int main() {
  int localVar1;
  int localVar2;

  printf("Sizes of primitives:\n");
  printf("- char: %d byte(s)\n", sizeof(char));
  printf("- int: %d byte(s)\n", sizeof(int));

  printf("Sizes of structures:\n");
  printf("- test struct: %d byte(s)\n", sizeof(my_test));
  printf("- enum value: %d byte(s)\n", sizeof(NORTH));
  printf("- array of ints (4): %d byte(s)\n", sizeof(intArray));
  printf("- array of structs (4): %d byte(s)\n", sizeof(testArray));
  printf("- union of int and float: %d byte(s)\n", sizeof(var1));
  printf("- union of float and double: %d byte(s)\n", sizeof(var2));

  printf("Memory Addresses:\n");
  printf("- var1 (global): %#x\n", &var1);
  printf("- var2 (global): %#x\n", &var2);
  printf("- localVar1: %#x\n", &localVar1);
  printf("- localVar2: %#x\n", &localVar2);
}