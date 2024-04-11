// 1. Palindrome Checker: Write a program that checks if a given string is a palindrome or not. A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).

#include <stdio.h>
#include <string.h>

int main () {
  char arr[40];

  printf("Enter a string: ");
  scanf("%s", arr);

  int length_of_arr = strlen(arr);
  int counter = 0;

  for(int count = 0; count < length_of_arr/2; count++) {
    if (arr[count] == arr[length_of_arr - count - 1]) {
      continue;
    } else {
      counter++;
      break;
    }
  }

  if (counter == 0) {
    printf("%s is a palindrome \n", arr);
  } else {
    printf("%s is not a palindrome \n", arr);
  }
}
