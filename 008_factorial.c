#include <stdio.h>

int main() {
  int value = 0;
  int factorial = 1;

  printf("Enter the number: ");
  scanf("%i", &value);

  for (int count = value; count >= 1; count--) {
    factorial *= count;
  }

  printf("%i is the factorial of %i", factorial, value);
}
