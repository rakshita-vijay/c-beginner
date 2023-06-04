/*
Electricity bill

first 100 = 8/unit
next 300 = 10/unit
next 300 = 13/unit
above = 15/unit

from user take name, no of units
*/

#include <stdio.h>

struct bill {
  char name[50];
  int units;
  int totalCost;
};

struct costBlock {
  int beginningOfBlock;
  int endingOfBlock;
  int costPerUnitForBlock;
};

int calcTotalCost(int numberOfUnits) {
  struct costBlock for1To100Units = {1, 100, 8};
  struct costBlock for101To400Units = {101, 400, 10};
  struct costBlock for401To700Units = {401, 700, 13};
  struct costBlock above700Units = {700, 0, 15};

  if ((for1To100Units.beginningOfBlock <= numberOfUnits) && (numberOfUnits <= for1To100Units.endingOfBlock)) {
    return numberOfUnits * (for1To100Units.costPerUnitForBlock);
  } else if ((for101To400Units.beginningOfBlock <= numberOfUnits) &&
             (numberOfUnits <= for101To400Units.endingOfBlock)) {
    // if 200 units, then 200 = 100+100
    // 800+1000 = 2800

    return ((for1To100Units.endingOfBlock) * (for1To100Units.costPerUnitForBlock)) +
           (numberOfUnits - (for1To100Units.endingOfBlock)) * (for101To400Units.costPerUnitForBlock);
  } else if ((for401To700Units.beginningOfBlock <= numberOfUnits) &&
             (numberOfUnits <= for401To700Units.endingOfBlock)) {
    // if 500 units, then 500 = 100+300+100
    // 800+3000+1300 = 5100

    return ((for1To100Units.endingOfBlock) * (for1To100Units.costPerUnitForBlock)) +
           (((for101To400Units.endingOfBlock) - (for1To100Units.endingOfBlock)) *
            (for101To400Units.costPerUnitForBlock)) +
           (numberOfUnits - for101To400Units.endingOfBlock) * (for401To700Units.costPerUnitForBlock);
  } else {
    // if 800 units, then 800 = 100+300+300+100
    // 800+3000+3900+1500 = 9200

    return (
        ((for1To100Units.endingOfBlock) * (for1To100Units.costPerUnitForBlock)) +
        (((for101To400Units.endingOfBlock) - (for1To100Units.endingOfBlock)) * (for101To400Units.costPerUnitForBlock)) +
        (((for401To700Units.endingOfBlock) - (for101To400Units.endingOfBlock)) *
         (for401To700Units.costPerUnitForBlock)) +
        (numberOfUnits - for401To700Units.endingOfBlock) * (above700Units.costPerUnitForBlock));
  }
}

int main() {
  struct bill person1;

  printf("Enter name of user: ");
  scanf("%s", person1.name);

  printf("Enter number of units consumed: ");
  scanf("%i", &person1.units);
  int numberOfUnits = person1.units;

  person1.totalCost = calcTotalCost(numberOfUnits);

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("BILL: \n");
  printf("Name: %s \n", person1.name);
  printf("Number of Units Consumed: %i \n", person1.units);
  printf("Total Cost: %i \n", person1.totalCost);
}
