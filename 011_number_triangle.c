#include <stdio.h>

int main() {
  int numberOfLines = 0;

  printf("Enter the number of lines to print: ");
  scanf("%i", &numberOfLines);

  for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++) {
    for (int numberOfSpaces = 0; numberOfSpaces < (numberOfLines - lineNumber); numberOfSpaces++) {
      printf(" ");
    }

    for (int numberOfIntegers = 0; numberOfIntegers <= lineNumber; numberOfIntegers++) {
      printf("%i", numberOfIntegers + 1);
    }

    for (int numberOfIntegers = lineNumber - 1; numberOfIntegers >= 0; numberOfIntegers--) {
      printf("%i", numberOfIntegers + 1);
    }

    printf("\n");
  }
}
