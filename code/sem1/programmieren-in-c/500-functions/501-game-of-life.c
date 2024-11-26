/* Game of life
The "game of life" is an old and very simple approach of simulating evolution
A 2-dimensional field of cells is regarded with a cell being either empty/dead
(0) or occupied/alive (1) The intial state can be chosen e.g. manually or using
some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are
directly horizontally, vertically, or diagonally adjacent. At each step in time,
the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs
caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by
overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the
next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be
populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation
is created by applying the above rules simultaneously to every cell in the seed
� births and deaths happen simultaneously, and the discrete moment at which this
happens is sometimes called a tick. (In other words, each generation is a pure
function of the one before.)  The rules continue to be applied repeatedly to
create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life.
//        Do it as teamwork (e.g. in teams with 2 or 3)
//        and benefit from being able to develop functions independently and
//        integrate them into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states',
// i.e. the system is oscillating between a few states. 

// TO DO optional 2: let
// the program find a start state such that the system stays alive and unstable
// for as long as possible 

// TO DO optional 3: Create a flicker-free output: Do
// not print each character separately, but write the output into a string,
// which is printed all at once 

// TO DO optional 4: extend the program such that
// the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Global 2-dim-array which contains the cells
char cells[30][50];

// TO DO: initialize cells, set most to 0, some to 1
void initialize_cells() {
  // for (int i = 0; i < 30; i++) {
  //   for (int j = 0; j < 50; j++) {
  //     if (rand() % 4 == 0) {
  //       cells[i][j] = 1;
  //     } else {
  //       cells[i][j] = 0;
  //     }
  //   }
  // }

  // Coordinates for the Gosper Glider Gun relative to the top-left of the grid
  int gun_coords[][2] = {
      {5, 1},  {5, 2},  {6, 1},  {6, 2},            // Block
      {5, 11}, {6, 11}, {7, 11},                    // Vertical line
      {4, 12}, {8, 12},                             // Wings
      {3, 13}, {9, 13}, {3, 14}, {9, 14},           // Outer boxes
      {6, 15},                                      // Center dot
      {4, 16}, {8, 16},                             // Inner wings
      {5, 17}, {6, 17}, {7, 17},                    // Vertical line
      {6, 18},                                      // Center dot
      {3, 21}, {4, 21}, {5, 21},                    // Left L shape
      {3, 22}, {4, 22}, {5, 22}, {2, 23}, {6, 23},  // Connectors
      {1, 25}, {2, 25}, {6, 25}, {7, 25},           // Right L shape
      {3, 35}, {3, 36}, {4, 35}, {4, 36}            // Small block
  };

  // Set the specified cells to 1
  for (size_t i = 0; i < sizeof(gun_coords) / (2 * sizeof(int)); i++) {
    int r = gun_coords[i][0];
    int c = gun_coords[i][1];
    if (r >= 0 && r < 30 && c >= 0 && c < 50) {  // Ensure within bounds
      cells[r][c] = 1;
    }
  }
}

// TO DO: Write output function to show the cells
void display_cells() {
  system("clear");

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      if (cells[i][j] == 1) {
        printf("X");
      } else {
        printf(".");
      }
    }

    printf("\n");
  }
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step() {
  // TO DO: Use this array for the calculation of the next step
  char cells_helper[30][50];
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      cells_helper[i][j] = cells[i][j];
    }
  }

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      int alive_neighbours = 0;
      for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
          if (k == 0 && l == 0) {
            continue;
          }

          if (i + k > 0 && j + l > 0 &&
              cells[(i + k) % 30][(j + l) % 50] == 1) {
            alive_neighbours++;
          }
        }
      }

      if (cells[i][j] == 1 && (alive_neighbours < 2 || alive_neighbours > 3)) {
        cells_helper[i][j] = 0;
      } else if (cells[i][j] == 0 && alive_neighbours == 3) {
        cells_helper[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      cells[i][j] = cells_helper[i][j];
    }
  }
}

// TO DO: Write a function that counts the occupied cells
int count_cells() {
  int count = 0;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      if (cells[i][j] == 1) {
        count++;
      }
    }
  }

  return count;
}

// Main program
int main() {
  srand(time(NULL));
  initialize_cells();
  int loop = 0;

  while (1) {
    display_cells();

    // Leave loop if there are no more occupied cells
    if (count_cells() == 0) break;
    if (!loop) {
      printf("Press enter");
      getchar();
      loop = 1;
    }

    evolution_step();
    usleep(50000);
  }
}