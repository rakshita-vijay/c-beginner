// Even/Odd Number

#include <stdio.h>

int main() {
  int num;

  printf("Enter the number to check: ");
  scanf("%i", &num);

  switch ((num % 2) != 0) {
  case 1: // 1 = True
  {
    printf("%i is odd", num);
    break;
  }
  case 0: // 0 = False
  {
    printf("%i is even", num);
    break;
  }
  }
}
