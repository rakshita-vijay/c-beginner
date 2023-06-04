#include <stdio.h>

int main() {
  int value = 0;
  int check = 0;

  printf("Enter the number to check: ");
  scanf("%i", &value);

  for (int count = 2; count <= (value / 2); count++) {
    if ((value % count) == 0) {
      printf("Not a Prime Number");
      check = 1;
      break;
    }
  }

  if (check == 0) {
    printf("Prime Number");
  }
}
