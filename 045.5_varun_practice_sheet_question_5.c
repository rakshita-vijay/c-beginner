// 5) a) Generate the given pattern.

// Value of n: 5
// 1
// 4 1
// 9 4 1
// 16 9 4 1
// 25 16 9 4 1

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
