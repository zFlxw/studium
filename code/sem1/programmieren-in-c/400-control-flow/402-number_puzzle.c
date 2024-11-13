/* number_puzzle.c
   Write a number puzzle program by completing the TO DOs

   TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly
   distributed in the array. -1 should mark the empty field.

   TO DO 2: get key and move pieces accordingly (if keystroke is valid)

   TO DO 3: Check, if puzzle is in correct order -> set sorted=1

   TO DO 4: Create a more fancy output, e.g. by creating frames around the
   numbers (Use a special character e.g. a block rather than '*') (Also, mark
   the empty field rather than showing -1)

            *********************
            *  1 *  2 *  3 *  4 *
            *********************
            *  5 *  6 *  7 *  8 *
            *********************
            *  9 * 10 * 11 * 12 *
            *********************
            * 13 * 14 * 15 ******
            *********************

   TO DO 5, optional: created an automatic, intelligent puzzle solver, which
   solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int puzzle[N][N];
int empty_i = -1, empty_j = -1;

int move(char direction) {
  if (empty_i == -1 || empty_j == -1) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (puzzle[i][j] == -1) {
          empty_i = i;
          empty_j = j;
          break;
        }
      }
    }
  }

  int tmp;

  switch (direction) {
    case 'w':
      if (empty_i - 1 < 0) {
        break;
      }

      tmp = puzzle[empty_i][empty_j];
      puzzle[empty_i][empty_j] = puzzle[empty_i - 1][empty_j];
      puzzle[empty_i - 1][empty_j] = tmp;

      empty_i -= 1;
      break;
    case 's':
      if (empty_i + 1 >= N) {
        break;
      }

      tmp = puzzle[empty_i][empty_j];
      puzzle[empty_i][empty_j] = puzzle[empty_i + 1][empty_j];
      puzzle[empty_i + 1][empty_j] = tmp;

      empty_i += 1;
      break;
    case 'a':
      if (empty_j - 1 < 0) {
        break;
      }

      tmp = puzzle[empty_i][empty_j];
      puzzle[empty_i][empty_j] = puzzle[empty_i][empty_j - 1];
      puzzle[empty_i][empty_j - 1] = tmp;

      empty_j -= 1;
      break;
    case 'd':
      if (empty_j + 1 >= N) {
        break;
      }

      tmp = puzzle[empty_i][empty_j];
      puzzle[empty_i][empty_j] = puzzle[empty_i][empty_j + 1];
      puzzle[empty_i][empty_j + 1] = tmp;

      empty_j += 1;
      break;
  }
}

int is_sorted() {
  int last = -2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (last > puzzle[i][j] &&
          !(i == N - 1 && j == N - 1 && puzzle[i][j] == -1)) {
        return 0;
      }

      last = puzzle[i][j];
    }
  }

  return 1;
}

int main() {
  srand(time(NULL));

  char key;         // This holds the current key entered by the player.
  char sorted = 0;  // This flag indicates whether the field is sorted.
  int i, j;

  for (i = 0; i < N * N; i++) {
    if (i != 15) {
      puzzle[i / N][i % N] = i + 1;
    } else {
      puzzle[i / N][i % N] = -1;
    }
  }

  for (int k = 0; k < 10; k++) {
    move("wasd"[rand() % 4]);
  }

  while (!sorted) {
    /* Output */
    printf("*********************\n");
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        if (puzzle[i][j] != -1) {
          printf("* %2d ", puzzle[i][j]);
        } else {
          printf("*    ");
        }
        if (j == N - 1) {
          printf("*\n");
        }
      }
      printf("*********************\n");
    }

    printf("move into direction?");
    printf("\n");
    key = getchar();
    if (key == '\n') {
      continue;
    }

    move(key);
    sorted = is_sorted();
  }

  printf("Puzzle solved! Here's the final result.\n");
  printf("*********************\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("* %2d ", puzzle[i][j]);
      if (j == N - 1) {
        printf("*\n");
      }
    }
    printf("*********************\n");
  }
}