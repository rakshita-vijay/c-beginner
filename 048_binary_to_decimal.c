#include <stdio.h>
#include <math.h>

int main () {
  int bin_num;
  printf("Enter a number in binary(0s and 1s): ");
  scanf("%d", &bin_num); // Ex: 00101

  int decimal_num = 0;
  int temp = 0;
  int length_of_bin_num = log10(bin_num) + 1;

  for(int count = 0; count < length_of_bin_num; count++) {
    temp = bin_num % 10;
    (temp == 1) ? (decimal_num += (pow(2, count) * temp)) : (decimal_num += 0);
    bin_num /= 10;
  }

  printf("The converted decimal number is: %d \n", decimal_num);
}
