#include <stdio.h>

void main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int *p_num;
  p_num = &num;

  printf("Number's value: %d \n", num);
  printf("Number's address: %d \n \n", &num);
  printf("Pointer: %p \n", p_num);
  printf("Pointer's address: %d \n", &p_num);
  printf("Pointer's value: %d \n", *p_num);
}
