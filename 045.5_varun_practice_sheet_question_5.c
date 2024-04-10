// 5) a) Generate the given pattern.

// Value of n: 5
// 1
// 4 1
// 9 4 1
// 16 9 4 1
// 25 16 9 4 1

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_rows;

  printf("Enter the number of lines: ");
  scanf("%d", &num_of_rows);

  for (int row_count = 1; row_count <= num_of_rows; row_count++) {
    for (int column_count = 1; column_count <= row_count; column_count++) {
      printf("%d ", (int) pow(row_count - column_count + 1, 2));
    }
    printf("\n");
  }
}
*/

// 5) b) Generate the given pattern.

// Value of n: 3
// 1 # # # # # # #
// 2 #   #   #   #
// 3 # # # # # # #
// 4 #   #   #
// 5 # # # # #
// 6 #   #
// 7 # # #

#include <stdio.h>
#include <math.h>

int main () {
  int num_of_square_rows;

  printf("Enter the squares of # in first line: ");
  scanf("%d", &num_of_square_rows);

  for (int column_index = 0; column_index < ((2 * num_of_square_rows) + 1); column_index++) {
    printf("# ");
  }

  printf("\n");

  int counter = 0;
  int num_of_square_rows_copy = num_of_square_rows;

  for(int row_count = 0; row_count < pow(((2 * num_of_square_rows) + floor(num_of_square_rows_copy/2)), 2); row_count++) {
    counter = 0;
    for (int column_index = 0; column_index < ((2 * num_of_square_rows) + 1); column_index++) {
      if (row_count % 2 == 0) {
        printf("#   ");
        column_index++;
      } else {
        printf("# ");
        counter = 1;
      }
    }
    printf("\n");
    num_of_square_rows -= (counter == 1) ? 1 : 0;
  }
}
