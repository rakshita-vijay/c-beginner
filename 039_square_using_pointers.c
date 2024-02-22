#include <stdio.h>
#include <math.h>

int square(int *p_num) {
  return pow(*p_num, 2);
}

void main () {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int *p_num;
  p_num = &num;

  int res = square(p_num);
  printf("Square of %d is %d", *p_num, res);
}
