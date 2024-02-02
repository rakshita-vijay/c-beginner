#include <stdio.h>
#include <math.h>

double fact(int count) {
  return (count == 1) ? 1 : (count * fact(count - 1));
}

float val(int num, long int count) {
  return (pow(-1, (count + 1))) * ((pow(num, count)) / fact(count)) + val(num, count + 2);
}

void main() {
  int num;
  long int count = 1;
  
  printf("Enter a number: ");
  scanf("%d", &num);
  
  float result = val(num, count);
  printf("The result is: %f", result);
}
