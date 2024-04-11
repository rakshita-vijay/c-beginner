// 1. Factorial Calculation: Write a program to calculate the factorial of a non-negative integer using recursion

#include <stdio.h>

int fact(int num) {
  return (num == 1) ? 1 : (num * fact(num - 1));
}

int main () {
  int num;
  printf("Enter the number you want to get the factorial of: ");
  scanf("%d", &num);

  printf("The factorial of %d is: %d \n", num, fact(num));
}
