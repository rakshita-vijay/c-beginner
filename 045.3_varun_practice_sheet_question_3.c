// 3) The Grid

// You are in an (n x n) grid of numbers. You are initially at the top-left cell. To navigate through the grid, you need to follow some instructions. The number in your current cell determines the next step you will take. Let x be the remainder when this number is divided by 4.

// If x = 0, go up.
// If x = 1, go right.
// If x = 2, go down.
// If x = 3, go left.

// You are given the number of steps you have to take. Find the number in the cell you land in after taking the required number of steps. If you step out of the grid during the process, output -1 instead.

// Value of n: 7
// Required number of steps: 5
// 53 89 94 63 47 67 18
// 69 69 50 38 35 25 83
// 19 80 43 78 84 81 11
// 50 28 47 64 70 71 53
// 63 52 82 70 28 37 31
// 77 67 80 40 58 28 96
// 55 25 53 64 73 20 78
// 80

// (You go right, right, down, down, and left in this case.)

#include <stdio.h>
#include <math.h>

int main() {
  int num_of_r_c;
  int number_of_steps;

  printf("Enter the number of rows and columns in an nxn matrix: ");
  scanf("%i", &num_of_r_c);
  printf("Enter the number of steps: ");
  scanf("%i", &number_of_steps);
  printf("\n");

  int matrix[num_of_r_c][num_of_r_c];
  for (int row_count = 0; row_count < num_of_r_c; row_count++) {
    for (int column_count = 0; column_count < num_of_r_c; column_count++) {
      printf("Enter the value of %dx%d: ", row_count + 1, column_count + 1);
      scanf("%i", &matrix[row_count][column_count]);
    }
  }

  printf("\n");

  printf("Your matrix is: \n");
  for (int row_count = 0; row_count < num_of_r_c; row_count++) {
    for (int column_count = 0; column_count < num_of_r_c; column_count++) {
      printf("%3i  ", matrix[row_count][column_count]);
    }
    printf("\n");
  }

  int current_cell[2] = {0, 0};
  int output_printed = 0;
  int step_count = 0;
  while (step_count < number_of_steps) {
    for (int row_count = 0; row_count < num_of_r_c; row_count++) {
      for (int column_count = 0; column_count < num_of_r_c; column_count++) {
        if ((matrix[row_count][column_count] % 4) == 0) {
          if (row_count == 0) {
            output_printed = -1;
            break;
          } else {
            current_cell[0] -= 1;
          }
        } else if ((matrix[row_count][column_count] % 4) == 1) {
          if (column_count == num_of_r_c - 1) {
            output_printed = -1;
            break;
          } else {
            current_cell[1] += 1;
          }
        } else if ((matrix[row_count][column_count] % 4) == 2) {
          if (row_count == num_of_r_c - 1) {
            output_printed = -1;
            break;
          } else {
            current_cell[0] += 1;
          }
        } else {
          if (column_count == 0) {
            output_printed = -1;
            break;
          } else {
            current_cell[1] -= 1;
          }
        }
      }
      if (output_printed == -1) {
      break;
      }
    }
  step_count++;
  }

  printf("\n");
  (output_printed == -1) ? printf("Exceeded row/column range: %d \n", output_printed) : printf("You are at %dx%d and the value is: %d \n", current_cell[0], current_cell[1], matrix[current_cell[0]][current_cell[1]]);
}
