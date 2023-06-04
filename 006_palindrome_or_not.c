#include <stdio.h>

int main() {
  int value = 0;
  int originalValue = 0;
  int reversedValue = 0;

  printf("Enter the number to check: ");
  scanf("%i", &value);
  originalValue = value;

  for (; originalValue != 0; originalValue = originalValue / 10) {
    int remainder = (originalValue % 10);
    reversedValue = (reversedValue * 10) + remainder;
  }

  if (reversedValue == value) {
    printf("%i is a palindrome", value);
  } else {
    printf("%i is not a palindrome", value);
  }
}
