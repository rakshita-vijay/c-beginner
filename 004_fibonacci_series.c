#include <stdio.h>

int main() {
  int numberOfValues;
  int x = 0;
  int y = 1;
  int switchVar = 0;

  printf("Enter the nunber of values to print in series: ");
  scanf("%i", &numberOfValues);

  printf("\n");
  printf("Fibonacci Series: \n");
  printf("%i %i ", x, y);

  for (int value = 2; value < numberOfValues; value++) {
    printf("%i ", (x + y));
    switchVar = (x + y);
    x = y;
    y = switchVar;
  }
}
