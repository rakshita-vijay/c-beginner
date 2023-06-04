/*

O/P:
*************
 ***********
  *********
   *******
    *****
     ***
      *

*/

#include <stdio.h>

int main() {
  int numberOfLines = 0;

  printf("Enter the number of lines to print: ");
  scanf("%i", &numberOfLines);

  for (int lineNumber = numberOfLines; lineNumber > 0; lineNumber--) {
    for (int numberOfSpaces = 0; numberOfSpaces < (numberOfLines - lineNumber); numberOfSpaces++) {
      printf(" ");
    }

    for (int numberOfAsterisks = numberOfLines; numberOfAsterisks > (numberOfLines - lineNumber); numberOfAsterisks--) {
      printf("*");
    }

    for (int numberOfAsterisks = numberOfLines - 1; numberOfAsterisks > (numberOfLines - lineNumber); numberOfAsterisks--) {
      printf("*");
    }

    printf("\n");
  }
}
