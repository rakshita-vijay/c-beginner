#include <stdio.h>
#include <math.h>

double fact(int count) {
  return (count == 1) ? 1 : (count * fact(count - 1));
}

float val(int num, long int count, long int power_for_sign) {
  int sign = (pow(-1, (power_for_sign + 1)));
  int numerator = (pow(num, count));
  int denomenator = fact(count);
  return count >= pow(10, 5) ? (sign * (numerator / denomenator)) : (sign * (numerator / denomenator) + val(num, count + 2, power_for_sign + 1));
}

void main() {
  int num;
  long int count = 1;
  long int power_for_sign = 1;
  
  printf("Enter a number: ");
  scanf("%d", &num);
  
  float res = val(num, count, power_for_sign);
  printf("The result is: %f", res);
}
