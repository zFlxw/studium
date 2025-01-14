#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
  size_t array[MAX_SIZE];
  size_t top;
} stack_list;

int is_empty(stack_list *stack) {
  return stack->top == -1;
}

int is_full(stack_list *stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(stack_list *stack, int element) {

}

int main() {
  printf("Test");
}