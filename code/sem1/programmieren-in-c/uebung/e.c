#include <stdlib.h>
#include <stdio.h>

typedef struct list_item {
  int data;
  struct list_item *next;
} list_item;

struct mydata {
  int a;
  char b;
  char c;
};

typedef struct mydata mydata;

int swap(mydata *struct_a, mydata *struct_b) {
  char b = struct_a->b;
  struct_a->b = struct_b->b;
  struct_b->b = b;
}

int main() {
  printf("%19", 2["Weird"]);
  return 0;
  mydata *struct_a = malloc(sizeof(mydata));
  mydata *struct_b = malloc(sizeof(mydata));

  (*struct_a).b = 'c';
  struct_b->b = 'd';
  swap(struct_a, struct_b);
  printf("%c\n", struct_a->b);
  printf("%c\n", struct_b->b);
}
