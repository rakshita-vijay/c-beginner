#include <stdio.h>
#include <math.h>

double fact(int count) {
  return count * fact(count - 1);
}

float val(int num) {
  long int count = 1;
  return (pow(-1, (count-1)))*((pow(num, count))/fact(count)) + val(count + 1);
}

void main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  float result = val(num);
  printf("The result is: %f", result);
}
