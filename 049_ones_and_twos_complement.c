#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {
  char bin_num[20];
  printf("Enter a number in binary(0s and 1s): ");
  scanf("%[^\n]", bin_num); // Ex: 00000

  int length_of_bin_num = strlen(bin_num);
  bin_num[length_of_bin_num] = '\0';

  char bin_num_ones_complement[length_of_bin_num];
  char bin_num_twos_complement[length_of_bin_num];

  // one's complement
  for (int count = 0; count < length_of_bin_num; count++) {
    if (bin_num[count] == '0') {
      bin_num_ones_complement[count] = '1';
    } else {
      bin_num_ones_complement[count] = '0';
    }
  }
  bin_num_ones_complement[length_of_bin_num] = '\0';
  printf("The one's complement of %s is: %s \n", bin_num, bin_num_ones_complement);

  // two's complement
  int carry_over_index = 1;
  for (int count = length_of_bin_num - 1; count >= 0; count--) {
    if (bin_num[count] == '0' && carry_over_index == 1) {
      bin_num_twos_complement[count] = '0';
    } else if (bin_num[count] == '1' && carry_over_index == 1){
      bin_num_twos_complement[count] = '1';
      carry_over_index = 0;
    } else {
      bin_num_twos_complement[count] = bin_num_ones_complement[count];
    }
  }
  bin_num_twos_complement[length_of_bin_num] = '\0';
  printf("The two's complement of %s is: %s \n", bin_num, bin_num_twos_complement);
}
