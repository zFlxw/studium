#include <stdio.h>

int main()
{
  int x = 25;
  int y = 14;

  unsigned int xu = 25;
  unsigned int yu = 14;

  printf("x & y = %d\n", x & y);
  printf("x | y = %d\n", x | y);
  printf("x ^ y = %d\n", x ^ y);

  printf("~x = %d\n", ~x);
  printf("~xu = %u\n", ~xu);
  printf("~y = %d\n", ~y);
  printf("~yu = %u\n", ~yu);

  printf("x << 1 = %d\n", x << 1); // LeftShift - Verdoppelung des Wertes
  printf("x >> 1 = %d\n", x >> 1); // RightShift - Halbierung des Wertes

  int a = 0, b = 0;

  a = a++;
  b = ++b;

  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}
