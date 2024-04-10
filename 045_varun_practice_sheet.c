// // c) You generated a fibonacci sequence of a certain length, starting with 1 and 1. Your friend does not like even numbers, so starting from the first number, everytime he encounters an even number, he deletes that number as well as the previous number. Output the new sequence.

// // Length of original sequence: 8
// // 1 3 13 21

// // (The original sequence is 1, 1, 2, 3, 5, 8, 13, and 21.)


#include <stdio.h>

int main() {
  int numberOfValues;
  int num_1 = 1;
  int num_2 = 1;
  int switchVar = 0;
  int sum = num_1 + num_2;

  printf("Enter the nunber of values to print in series: ");
  scanf("%i", &numberOfValues);

  printf("\n");
  printf("Fibonacci Series Sum: \n");

  for (int value = 2; value < numberOfValues; value++) {
    switchVar = (num_1 + num_2);
    sum += switchVar;
    num_1 = num_2;
    num_2 = switchVar;
  }

  printf("Sum: %i", sum);
}
