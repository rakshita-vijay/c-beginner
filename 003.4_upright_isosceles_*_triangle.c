/*

O/P:
      *
     ***
    *****
   *******
  *********
 ***********
*************

*/

#include <stdio.h>

int main() {
  int numberOfLines = 0;

  printf("Enter the number of lines to print: ");
  scanf("%i", &numberOfLines);

  for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++) {
    for (int numberOfSpaces = 0; numberOfSpaces < (numberOfLines - lineNumber - 1); numberOfSpaces++) {
      printf(" ");
    }

    for (int numberOfAsterisks = 0; numberOfAsterisks <= lineNumber; numberOfAsterisks++) {
      printf("*");
    }

    for (int numberOfAsterisks = lineNumber - 1; numberOfAsterisks >= 0; numberOfAsterisks--) {
      printf("*");
    }

    printf("\n");
  }
}
