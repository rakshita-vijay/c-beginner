// linked functions

#include <math.h>
#include <stdio.h>

int gcd(int num1, int num2);
float absValue(float num);
float sqRoot(float num);

// gcd of two numbers
int gcd(int num1, int num2) {
  int factor = 1;
  int gcd = 1;

  printf("The numbers entered are: %d and %d \n", num1, num2);

  if (num1 < 0) {
    printf("1> ");
    num1 = absValue(num1);
  }
  if (num2 < 0) {

    printf("2> ");
    num2 = absValue(num2);
  }

  for (factor = 1; factor <= num1 && factor <= num2; factor++) {
    if (num1 % factor == 0 && num2 % factor == 0) {
      gcd = factor;
    }
  }

  printf("The greatest common divisor of the numbers entered is: %i \n", gcd);
}

// absolute value of one number
float absValue(float num) {
  float absNum = num;

  if (num < 0) {
    absNum = -num;
  }

  printf("The number entered is: %f \n", num);
  printf("The absolute value of the number entered is: %f \n", absNum);

  return absNum;
}

// square root of one number
float sqRoot(float num) {
  float absNum;
  float sqRootOfNum;

  absNum = absValue(num);
  sqRootOfNum = sqrt(absNum);

  if (num < 0) {
    printf("The number entered is negative. \n");
    printf("The square root of the negative number entered is: %fi \n", sqRootOfNum);
  }

  else {
    printf("The square root of the number entered is: %f \n", sqRootOfNum);
  }
}

int main() {
  printf("To find the gcd: \n");
  gcd(-7, -36); // checked, working correctly - linked

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("To find the absolute value: \n");
  absValue(-34.5); // checked, working correctly - linked

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("To find the square root: \n");
  sqRoot(-45.6); // checked, working correctly - linked
}
