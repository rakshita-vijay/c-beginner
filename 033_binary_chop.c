// Binary Chop

#include <stdio.h>

int main() {
  int lenOfArrOfNum;
  int numToSearch;
  char result = 'n';
  int index;

  printf("Enter length of array of numbers: ");
  scanf("%i", &lenOfArrOfNum);

  int arrOfNum[lenOfArrOfNum];

  printf("Enter the array values: \n");
  for (index = 0; index < lenOfArrOfNum; index++) {
    printf("%i> ", (index + 1));
    scanf("%i", &arrOfNum[index]);
  }

  printf("Enter a number to search in the array of numbers: ");
  scanf("%i", &numToSearch);

  for (index = 0; index < lenOfArrOfNum; index++) {
    if (numToSearch == arrOfNum[index]) {
      result = 'y';
      break;
    }
  }

  if (result == 'y') {
    printf("The number you entered, %i, is found at %i", numToSearch, (index + 1));
  } else {
    printf("The number you entered, %i, is not found", numToSearch);
  }
}
