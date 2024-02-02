#include <stdio.h>
#include <math.h>

int fact(int count) {
  return count * fact(count-1);
}

int val(int num) {
  int count = 1;
  return (pow(-1, (count-1)))*((pow(num, count))/fact(count)) + val(num, count + 1);
}

void main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int result = val(num);
  printf("The result is: %d", result);
}
