// Vowel / Consonant

#include <stdio.h>

int main() {
  char alphabet;

  printf("Enter the character to check: ");
  scanf("%c", &alphabet);

  switch (alphabet) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U': {
    printf("\'%c\' is a vowel", alphabet);
    break;
  }
  default: {
    printf("\'%c\' is a consonant", alphabet);
  }
  }
}
