// 1. Palindrome Checker: Write a program that checks if a given string is a palindrome or not. A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).

/*
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
*/

// Anagram Checker: Create a program that checks if two given strings are anagrams of each other. Anagrams are words or phrases formed by rearranging the letters of another word or phrase.

#include <stdio.h>
#include <string.h>

int main () {
  char arr_1[40];
  char arr_2[40];

  printf("Enter string 1: ");
  scanf("%[^\n]", arr_1);

  fflush(stdin);

  printf("Enter string 2: ");
  scanf("%[^\n]", arr_2);

  int length_of_arr_1 = strlen(arr_1);
  int length_of_arr_2 = strlen(arr_2);

  // removing all blank spaces from the first string
  for (int count = 0; count < length_of_arr_1; count++) {
    if (arr_1[count] == ' ') {
      for (int count_no_space = count; count_no_space < length_of_arr_1; count_no_space++) {
        arr_1[count_no_space] = arr_1[count_no_space + 1];
      }
      length_of_arr_1--;
    }
  }
  arr_1[length_of_arr_1] = '\0';

  // removing all blank spaces from the second string
  for (int count = 0; count < length_of_arr_2; count++) {
    if (arr_2[count] == ' ') {
      for (int count_no_space = count; count_no_space < length_of_arr_2; count_no_space++) {
        arr_2[count_no_space] = arr_2[count_no_space + 1];
      }
      length_of_arr_2--;
    }
  }
  arr_2[length_of_arr_2] = '\0';

  // checking if string lengths are same without blank spaces
  if (length_of_arr_1 != length_of_arr_2) {
    printf("They are not anagrams :( \n");
  } else {
    for (int count = 0; arr_1[count] != '\0'; count++) {
      char character_to_count = arr_1[count];

      int alphabet_counter_1 = 0;
      int alphabet_counter_2 = 0;

      // counting in first array
      for (int alpha_count_1 = 0; alpha_count_1 < length_of_arr_1; alpha_count_1++) {
        if (arr_1[alpha_count_1] == character_to_count) {
          alphabet_counter_1++;
        }
      }

      // counting in second array
      for (int alpha_count_2 = 0; alpha_count_2 < length_of_arr_2; alpha_count_2++) {
        if (arr_2[alpha_count_2] == character_to_count) {
          alphabet_counter_2++;
        }
      }

      if (alphabet_counter_1 == alphabet_counter_2) {
        continue;
      } else {
        printf("They are not anagrams :( \n");
        break;
      }
    }
    printf("They are anagrams :) \n");
  }
}
