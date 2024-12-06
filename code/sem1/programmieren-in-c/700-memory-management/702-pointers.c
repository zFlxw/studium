/* pointers.c
   TO DO 1:  Extend/modify the address_list.c program such that the student data
   is not stored in a global but in local data structures in main.

   TO DO 2:  Use pointers/call by reference to pass student data to the
   different functions.

   TO DO 3:  use typedef to define a type for 'struct person' and use this type

   Some code snippets are given below.
*/

void print_student(struct person *s) {
  printf("%s", (*s).first_name);
  // as the notation (*s).firstname is somewhat clumsy, there is a special
  // operator for this frequently used * . operation:
  printf("%s", s->first_name);
}

int main() {
  print_student(&students[i]);
  // or simpler:
  print_student(students +
                i);  // Note, that this addition of i to a pointer is special as
                     // it considers the size of type pointed to
}
