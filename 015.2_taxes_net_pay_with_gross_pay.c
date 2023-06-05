// with functions, with struct

#include <stdio.h>

struct taxBlock {
  int beginningOfBlock;
  int endingOfBlock;
  float taxForBlock;
};

struct taxBlock arr[] = {{1, 300000, 0.00}, {300001, 400000, 0.05}, {400001, 550000, 0.10}, {550001, 750000, 0.15}, {750001, 999999999, 0.20}};

float calcTaxes(float grossPay) {
  float tax = 0.0;
  int index;
  float runningTotal;

  for (index = 0, runningTotal = grossPay; runningTotal != 0; index++) { // runningTotal = 550000, 250000
    int bob = arr[index].beginningOfBlock;
    int eob = arr[index].endingOfBlock;
    float tfb = arr[index].taxForBlock;
    int slab = (eob - bob + 1);

    if (runningTotal <= slab) {
      tax += (runningTotal * tfb);
      break;
    } else {
      tax += (slab * tfb);
      runningTotal -= slab;
    }
  }
  return tax;
}

float calcNetPay(float grossPay) {
  return grossPay - calcTaxes(grossPay);
}

int main() {
  float grossPay;

  printf("Enter the gross pay: ");
  scanf("%f", &grossPay);
  printf("\n");

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("Gross Pay: %.2f \n", grossPay);
  printf("Taxes: %.2f \n", calcTaxes(grossPay));
  printf("Net Pay: %.2f \n", calcNetPay(grossPay));
}
