// Number of Days in a Month

#include <stdio.h>

int main() {
  int monthNumber;

  printf("Enter the number of the month you want to print (1-12): ");
  scanf("%i", &monthNumber);

  switch (monthNumber) {
  case 1: {
    printf("1> January: 31 \n");
    break;
  }
  case 2: {
    printf("2> February: 28 \n");
    break;
  }
  case 3: {
    printf("3> March: 31 \n");
    break;
  }
  case 4: {
    printf("4> April: 30 \n");
    break;
  }
  case 5: {
    printf("5> May: 31 \n");
    break;
  }
  case 6: {
    printf("6> June: 30 \n");
    break;
  }
  case 7: {
    printf("7> July: 31 \n");
    break;
  }
  case 8: {
    printf("8> August: 31 \n");
    break;
  }
  case 9: {
    printf("9> September: 30 \n");
    break;
  }
  case 10: {
    printf("10> October: 31 \n");
    break;
  }
  case 11: {
    printf("11> November: 30 \n");
    break;
  }
  case 12: {
    printf("12> December: 31 \n");
    break;
  }
  default: {
    printf("Error. You have chosen a number out of bounds.\n");
  }
  }
}
