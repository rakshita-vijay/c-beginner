// LAB SHEET: 4

// Q1. Print the Fibonacci series for a given n.

/*
#include <stdio.h>

int main () {
  int num_1;
  int num_2;
  int num_of_digits;

  printf("Enter the first number of the series: ");
  scanf("%d", &num_1);
  printf("Enter the second number of the series: ");
  scanf("%d", &num_2);
  printf("Enter the number of digits in the series to print: ");
  scanf("%d", &num_of_digits);

  printf("The Fibonacci Series is: ");

  int temp = 0;

  for (int count = 0; count < num_of_digits; count++) {
    temp = num_1;
    printf("%d ", temp);
    num_1 = num_2;
    num_2 += temp;
  }

  printf("\n");
}
*/

// Q2. Print all prime numbers between 0 and n. Take n as input.

// Q3. Write a program to calculate the sum of the digits of an integer.

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num;
  printf("Enter the number to find the sum of digits of: ");
  scanf("%d", &num);

  int sum = 0;
  for (int count = 0; num > 0; count++) {
    sum += num % 10;
    num /= 10;
  }

  printf("Sum of digits is: %d \n", sum);
}
*/

// Q4. Check whether the given number is Armstrong or not.

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num;
  printf("Enter the number to check if Armstrong or not: ");
  scanf("%d", &num);

  int num_copy = num;

  int length_of_num = log10(num) + 1;

  int sum = 0;
  for (int count = 0; num > 0; count++) {
    sum += pow((num % 10), length_of_num);
    num /= 10;
  }

  if (num_copy == sum) {
    printf("%d is an Armstrong number \n", num_copy);
  } else {
    printf("%d is not an Armstrong number \n", num_copy);
  }
}
*/

// Extra Practice Questions:
// (1) Write a C program to find the reverse number of a given positive number.

/*
#include <stdio.h>
#include <math.h>

int main() {
  int num;
  printf("Enter the number to check if Armstrong or not: ");
  scanf("%d", &num);

  int num_copy = num;
  int num_rev = 0;

  int length_of_num = log10(num) + 1;

  for (int count = 0; count < length_of_num; count++) {
    num_rev += ((pow(10, length_of_num - count)) * (num % 10));
    num /= 10;
  }

  printf("The reverse of %d is %d \n", num_copy, num_rev);
}
*/

// (2) Write a C program to print all four-digit Armstrong numbers

/*
#include <stdio.h>
#include <math.h>

int main () {
  int sum;
  int length_of_num;

  for (int number = 1000; number < 9999; number++) {
    sum = 0;
    length_of_num = log10(number) + 1;
    for (int number_copy = number; number_copy > 0; number_copy /= 10) {
      sum += pow((number_copy % 10), length_of_num);
    }

    if (number == sum) {
      printf("%d is an Armstrong number \n", number);
      continue;
    }
  }
}
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// LAB SHEET: 6

  // Q.4 Using if and while, print 10 numbers per line. Input given is a number between 1 and 50

  /*
  #include <stdio.h>

  int main () {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num > 50) {
      num = 50;
    }
    int count = 0;
    while (num >= 1 && count < 10) {
      printf("%3d", num);
      num--;
      count++;
      if (count == 10) {
        printf("\n");
        count = 0;
      }
    }
    printf("\n");
  }
  */

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// LAB SHEET: 7

// Q.1 Generate Pascal’s triangle of any length. Usage of Conditionals and loops for generating the triangle.

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_lines;
  printf("Enter the number of lines: ");
  scanf("%d", &num_of_lines);

  int num_to_print = 0;

  for (int line_count = 0; line_count < num_of_lines; line_count++) {
    for (int space_count = 0; space_count < 2 * (num_of_lines - line_count); space_count++) {
      printf(" ");
    }
    num_to_print = pow(11, line_count);
    for (int index = 0; num_to_print > 0; index++) {
      printf("%4d", num_to_print % 10);
      num_to_print /= 10;
    }
    printf("\n");
  }
}
*/

// Q.2 Write a program using nested for loops that generate a pattern of numbers and #s as shown in the output.

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_lines;
  printf("Enter the number of lines: ");
  scanf("%d", &num_of_lines);

  for (int row_count = 0; row_count < num_of_lines; row_count++) {
    for (int num_to_print = 0; num_to_print <= row_count; num_to_print++) {
      printf("%d", num_to_print + 1);
    }
    for (int num_to_print = num_of_lines - row_count - 1; num_to_print > 0; num_to_print--) {
      printf("#");
    }
    printf("\n");
  }
}
*/

// Q.3 Write a program using nested for loops that generate a pattern as shown in the output of the below program.

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_lines;
  printf("Enter the number of lines: ");
  scanf("%d", &num_of_lines);

  for (int row_count = 0; row_count < num_of_lines; row_count++) {
    for (int space_count_left = num_of_lines - row_count; space_count_left > 0; space_count_left--) {
      printf(" ");
    }
    for (int star_count_left = 0; star_count_left < (2 * row_count) + 1; star_count_left++) {
      printf("*");
    }
    for (int space_count_middle = 2 * (num_of_lines - row_count) - 1; space_count_middle > 0; space_count_middle--) {
      printf(" ");
    }
    for (int star_count_right = 0; star_count_right < (2 * row_count) + 1; star_count_right++) {
      printf("*");
    }
    printf("\n");
  }
}
*/

// Task #1

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_lines;
  printf("Enter the number of lines: ");
  scanf("%d", &num_of_lines);

  for (int row_count = 0; row_count < num_of_lines; row_count++) {
    for (int hash_count = 0; hash_count < row_count; hash_count++) {
      printf("#");
    }
    for (int num_to_print = 1; num_to_print <= num_of_lines - row_count; num_to_print++) {
      printf("%d", num_to_print + row_count);
    }
    printf("\n");
  }
}
*/

// Task #2

/*
#include <stdio.h>
#include <math.h>

int main () {
  int num_of_lines;
  printf("Enter the number of lines: ");
  scanf("%d", &num_of_lines);

  for (int row_count = 0; row_count < num_of_lines; row_count++) {
    for (int num_to_print = 0; num_to_print <= row_count; num_to_print++) {
      printf("%d", num_to_print + 1);
    }
    for (int num_to_print = num_of_lines - row_count; num_to_print > 0; num_to_print--) {
      printf("#");
    }
    printf("\n");
  }
}
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// LAB SHEET: 8

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// LAB SHEET: 9

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// LAB SHEET: 10
