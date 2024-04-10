/*
a) Given the length and the first two numbers, generate a fibonacci sequence.

Length: 6
First number: 2
Second number: 5
2 5 7 12 19 31
*/

#include <stdio.h>

int main () {
  int num_1;
  int num_2;
  int temp_num;
  int length;

  printf("Enter the first number: ");
  scanf("%d", &num_1);
  printf("Enter the second number: ");
  scanf("%d", &num_2);

  printf("Enter the number of digits to be printed: ");
  scanf("%d", &length);

  int fibonacci[length] = {num_1, num_2};

  for (int count = 0; count < length; count++) {
    fibonacci[count + 2] = fibonacci[count] + fibonacci[count + 1];
  }

  printf("\n");

  for (int count = 0; count < length; count++) {
    printf("%d ", &fibonacci[count]);
  }
}
