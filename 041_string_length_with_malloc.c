#include <stdio.h>
#include <stdlib.h>

int main () {
  int size = 0;
  printf("Enter the size/length of the string to be entered: ");
  scanf("%d", &size);

  char *text = NULL;
  text = (char *) malloc (size * sizeof(char));

  if (text != NULL) {
    printf("Enter a string: ");
    scanf(" ");
    gets(text);
    printf("The string entered is: %s \n", text);
  }

  free(text);
  text = NULL;
}
