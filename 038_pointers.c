#include <stdio.h>

void main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int *p_num;
  p_num = &num;

  printf("Number entered: %d", num);
  printf("Number's address: %d", &num);

}
