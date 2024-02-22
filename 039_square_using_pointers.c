#include <stdio.h>
#include <math.h>

int square(int *p_num_loc) {
  return pow(*p_num_loc, 2);
}

int main () {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int *p_num;
  p_num = &num;

  int res = square(p_num);
  printf("Square of %d is %d \n", *p_num, res);
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

#include <stdio.h>
#include <math.h>

void square(int *p_num_loc) {
  *p_num_loc *= *p_num_loc;
}

int main () {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int copy_of_num = num;

  int *p_num;
  p_num = &num;

  square(p_num);
  printf("Square of %d is %d \n", copy_of_num, *p_num);
}
