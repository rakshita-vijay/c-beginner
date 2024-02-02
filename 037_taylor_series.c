#include <stdio.h>
#include <math.h>

double fact(long int count) {
  return (count == 1) ? 1 : (count * fact(count - 1));
}

float val(float num, long int count, long int power_for_sign) {
  float sign = (pow(-1, (power_for_sign + 1)));
  float numerator = (pow(num, count));
  float denominator = fact(count);
  return (count >= pow(10, 3)) ? (sign * (numerator / denominator)) : (sign * (numerator / denominator) + val(num, count + 2, power_for_sign + 1));
}

int main() {
  float num;
  long int count = 1;
  long int power_for_sign = 1;
  
  printf("Enter a number: ");
  scanf("%f", &num);
  
  float res = val(num, count, power_for_sign);
  printf("The result is: %f", res);
  return 0;
}
