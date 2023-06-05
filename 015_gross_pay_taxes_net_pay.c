/*

// with functions

#include <stdio.h>

float calcGrossPay(float numberOfHoursWorked) {
  float hourlyPayUnderFortyHours = 12.0;
  float hourlyPayAboveFortyHours = 18.0;

  if (numberOfHoursWorked <= 40.0) {
    return (numberOfHoursWorked * hourlyPayUnderFortyHours);
  }

  else if (numberOfHoursWorked > 40.0) {
    return (40.0 * hourlyPayUnderFortyHours) + ((numberOfHoursWorked - 40.0) * hourlyPayAboveFortyHours);
  }
}

float calcTaxes(float numberOfHoursWorked) {
  float grossPay = calcGrossPay(numberOfHoursWorked);
  float taxFirstThreeHun = 0.15;
  float taxNextOneFifty = 0.2;
  float taxRest = 0.25;

  if (grossPay <= 300) {
    return grossPay * taxFirstThreeHun;
  }

  else if (grossPay > 300 && grossPay <= 450) {
    return (300 * taxFirstThreeHun) + ((grossPay - 300) * taxNextOneFifty);
  }

  else if (grossPay > 450) {
    // taxes = ((300*taxFirstThreeHun) + (150*taxNextOneFifty) + ((grossPay-450)*taxRest));
    return 75 + ((grossPay - 450) * taxRest);
  }
}

float calcNetPay(float numberOfHoursWorked) {
  return calcGrossPay(numberOfHoursWorked) - calcTaxes(numberOfHoursWorked);
}

int main() {
  float numberOfHoursWorked;

  printf("Enter the number of hours a person has worked: ");
  scanf("%f", &numberOfHoursWorked);
  printf("\n");

  // numberOfHoursWorked = 30.0; // 40*12 + 5*18 = 570

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("Number of Hours Worked: %.2f \n", numberOfHoursWorked);

  printf("Gross Pay: %.2f \n", calcGrossPay(numberOfHoursWorked));
  printf("Taxes: %.2f \n", calcTaxes(numberOfHoursWorked));
  printf("Net Pay: %.2f \n", calcNetPay(numberOfHoursWorked));
}

*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// Gross Pay, Taxes, Net Pay - to be calculated

#include <stdio.h>

struct taxBlock {
  int beginningOfBlock;
  int endingOfBlock;
  float taxForBlock;
};

float calcTaxes(float grossPay) {
  float tax = 0.0;
  int index;
  float initialPay;
  initialPay = grossPay;

  struct taxBlock arr[] = {{1, 300000, 0.00}, {300001, 400000, 0.05}, {400001, 550000, 0.10}, {550001, 750000, 0.15}, {750001, 0, 0.20}};

  for (index = 0, initialPay = grossPay; initialPay != 0; index++) { // initialPay = 550000, 250000
    if (initialPay <= (((arr[index]).endingOfBlock) - ((arr[index]).beginningOfBlock) + 1)) {
      tax += (initialPay * ((arr[index]).taxForBlock));
      break;
    } else {
      tax += ((((arr[index]).endingOfBlock) - ((arr[index]).beginningOfBlock) + 1) * ((arr[index]).taxForBlock));
      initialPay -= (((arr[index]).endingOfBlock) - ((arr[index]).beginningOfBlock) + 1);
    }
  }
  return tax;
}

/*
  if (((taxBlockOne.beginningOfBlock) <= grossPay) && (grossPay <= (taxBlockOne.endingOfBlock))) {
    return (grossPay * (taxBlockOne.taxForBlock));
  }

  else if (((taxBlockTwo.beginningOfBlock) <= grossPay) && (grossPay <= (taxBlockTwo.endingOfBlock))) {
    return (((taxBlockOne.endingOfBlock) * (taxBlockOne.taxForBlock)) + ((grossPay - (taxBlockOne.endingOfBlock)) * (taxBlockTwo.taxForBlock)));
  }

  else if (((taxBlockThree.beginningOfBlock) <= grossPay) && (grossPay <= (taxBlockThree.endingOfBlock))) {
    return (((taxBlockOne.endingOfBlock) * (taxBlockOne.taxForBlock)) + (((taxBlockTwo.endingOfBlock) - (taxBlockOne.endingOfBlock)) * (taxBlockTwo.taxForBlock)) + ((grossPay - (taxBlockTwo.endingOfBlock)) * (taxBlockThree.taxForBlock)));
  }

  else if (((taxBlockFour.beginningOfBlock) <= grossPay) && (grossPay <= (taxBlockFour.endingOfBlock))) {
    return (((taxBlockOne.endingOfBlock) * (taxBlockOne.taxForBlock)) + (((taxBlockTwo.endingOfBlock) - (taxBlockOne.endingOfBlock)) * (taxBlockTwo.taxForBlock)) + (((taxBlockThree.endingOfBlock) - (taxBlockTwo.endingOfBlock)) * (taxBlockThree.taxForBlock)) + ((grossPay - (taxBlockThree.endingOfBlock)) * (taxBlockFour.taxForBlock)));
  }

  else if (((taxBlockFive.beginningOfBlock) <= grossPay) && (grossPay <= (taxBlockFive.endingOfBlock))) {
    return (((taxBlockOne.endingOfBlock) * (taxBlockOne.taxForBlock)) + (((taxBlockTwo.endingOfBlock) - (taxBlockOne.endingOfBlock)) * (taxBlockTwo.taxForBlock)) + (((taxBlockThree.endingOfBlock) - (taxBlockTwo.endingOfBlock)) * (taxBlockThree.taxForBlock)) + (((taxBlockFour.endingOfBlock) - (taxBlockThree.endingOfBlock)) * (taxBlockFour.taxForBlock)) + ((grossPay - (taxBlockFour.endingOfBlock)) * (taxBlockFive.taxForBlock)));
  }
*/

float calcNetPay(float grossPay) {
  return grossPay - (calcTaxes(grossPay));
}

int main() {
  float grossPay;

  printf("Enter the gross pay: ");
  scanf("%f", &grossPay);
  printf("\n");

  // numberOfHoursWorked = 30.0; // 40*12 + 5*18 = 570

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("Gross Pay: %.2f \n", grossPay);
  printf("Taxes: %.2f \n", calcTaxes(grossPay));
  printf("Net Pay: %.2f \n", calcNetPay(grossPay));
}
