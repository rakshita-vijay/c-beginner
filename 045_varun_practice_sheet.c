// 1) c) You generated a fibonacci sequence of a certain length, starting with 1 and 1. Your friend does not like even numbers, so starting from the first number, everytime he encounters an even number, he deletes that number as well as the previous number. Output the new sequence.

// Length of original sequence: 8
// 1 3 13 21

// (The original sequence is 1, 1, 2, 3, 5, 8, 13, and 21.)

/*
#include <stdio.h>

int main() {
  int numberOfValues;
  int num_1 = 1;
  int num_2 = 1;
  int switchVar = 0;
  int sum = num_1 + num_2;

  printf("Enter the number of values to print in series: ");
  scanf("%i", &numberOfValues);

  printf("\n");
  printf("Fibonacci Series Sum: \n");

  for (int value = 2; value < numberOfValues; value++) {
    switchVar = (num_1 + num_2);
    sum += switchVar;
    num_1 = num_2;
    num_2 = switchVar;
  }

  printf("Sum: %i \n", sum);
}
*/

// 2) a) Given an (n x n) matrix, find the sum of the squares of the diagonal elements.

// Value of n: 3
// 1 2 3
// 3 4 5
// 5 6 7
// 66

/*
#include <stdio.h>
#include <math.h>

int main() {
  int num_of_r_c;

  printf("Enter the number of rows and columns in an nxn matrix: ");
  scanf("%i", &num_of_r_c);
  printf("\n");

  int matrix[num_of_r_c][num_of_r_c];
  int sum = 0;

  for (int row_count = 0; row_count < num_of_r_c; row_count++) {
    for (int column_count = 0; column_count < num_of_r_c; column_count++) {
      printf("Enter the value of %dx%d: ", row_count + 1, column_count + 1);
      scanf("%i", &matrix[row_count][column_count]);

      sum += (row_count == column_count) ? pow(matrix[row_count][column_count], 2) : 0;
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

  printf("\n");

  printf("Sum of diagonal elements is: %i \n", sum);
}
*/

// 2) b) Given an (n x m) matrix, find the matrix obtained by multiplying it with its transpose.

// Value of n: 2
// Value of m: 3
// 1 2 3
// 4 5 6
// 14 32
// 32 77

/*
#include <stdio.h>
#include <math.h>

int main() {
  int num_of_r;
  int num_of_c;

  printf("Enter the number of rows in an mxn matrix: ");
  scanf("%i", &num_of_r);
  printf("Enter the number of columns in an mxn matrix: ");
  scanf("%i", &num_of_c);
  printf("\n");

  int matrix[num_of_r][num_of_c];
  int matrix_transpose[num_of_c][num_of_r];
  int matrix_product[num_of_r][num_of_r];

  for (int row_count = 0; row_count < num_of_r; row_count++) {
    for (int column_count = 0; column_count < num_of_c; column_count++) {
      printf("Enter the value of %dx%d: ", row_count + 1, column_count + 1);
      scanf("%i", &matrix[row_count][column_count]);
      matrix_transpose[column_count][row_count] = matrix[row_count][column_count];
    }
  }

  printf("\n");
  printf("Your %dx%d matrix is: \n", num_of_r, num_of_c);
  for (int row_count = 0; row_count < num_of_r; row_count++) {
    for (int column_count = 0; column_count < num_of_c; column_count++) {
      printf("%3i  ", matrix[row_count][column_count]);
    }
    printf("\n");
  }

  printf("\n");
  printf("Your %dx%d matrix's %dx%d transpose is: \n", num_of_r, num_of_c, num_of_c, num_of_r);
  for (int row_count = 0; row_count < num_of_c; row_count++) {
    for (int column_count = 0; column_count < num_of_r; column_count++) {
      printf("%3i  ", matrix_transpose[row_count][column_count]);
    }
    printf("\n");
  }

  // multiplying matrix and matrix_transpose
  for (int row_count = 0; row_count < num_of_r; row_count++) {
    for (int column_count = 0; column_count < num_of_r; column_count++) {
      matrix_product[row_count][column_count] = 0;
      for (int index = 0; index < num_of_c; index++) {
        matrix_product[row_count][column_count] += matrix[row_count][index] * matrix_transpose[index][column_count];
      }
    }
  }

  printf("\n");

  printf("Your multiplied %dx%d matrix is: \n", num_of_r, num_of_r);
  for (int row_count = 0; row_count < num_of_r; row_count++) {
    for (int column_count = 0; column_count < num_of_r; column_count++) {
      printf("%3i  ", matrix_product[row_count][column_count]);
    }
    printf("\n");
  }
}
*/
