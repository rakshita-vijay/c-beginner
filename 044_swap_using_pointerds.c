#include <stdio.h>

void swap(*p_1, *p_2) {
  int temp = *p_1;
  *p_1 = *p_2;
  *p_2 = temp;
}

int main () {
  int a = 1, b = 2;
  int *p_a = &a;
  int *p_b = &b;
  swap(*p_a, *p_b);
  printf("a = %d \nb = %d", *p_a, *p_b);
}
