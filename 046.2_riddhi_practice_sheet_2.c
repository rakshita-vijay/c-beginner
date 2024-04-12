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

// 2. Anagram Checker: Create a program that checks if two given strings are anagrams of each other. Anagrams are words or phrases formed by rearranging the letters of another word or phrase.

/*
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
*/

// 3. String Reversal: Write a program to reverse a given string without using any library function.

/*
#include <stdio.h>

int str_len(char arr[]) {
  int length_of_arr = 0;
  for (int count = 0; arr[count] != '\0'; count++) {
    length_of_arr++;
  }
  return length_of_arr;
}

int main() {
  char arr[50];
  char arr_rev[50];

  printf("Enter the string: ");
  scanf("%[^\n]", arr);

  fflush(stdin);

  int length_of_arr = str_len(arr);

  for(int count = 0; count < length_of_arr; count++) {
    arr_rev[count] = arr[length_of_arr - count - 1];
  }

  arr_rev[length_of_arr] = '\0';

  printf("The reversed string is: %s \n", arr_rev);
}
*/

// 4. String Concatenation: Implement a function to concatenate two strings without using any library function.

/*
#include <stdio.h>

int str_len(char arr[]) {
  int length_of_arr = 0;
  for (int count = 0; arr[count] != '\0'; count++) {
    length_of_arr++;
  }
  return length_of_arr;
}

int main () {
  char arr_1[40];
  char arr_2[40];
  char arr_concat[80];

  printf("Enter string 1: ");
  scanf("%[^\n]", arr_1);

  fflush(stdin);

  printf("Enter string 2: ");
  scanf("%[^\n]", arr_2);

  int length_of_arr_1 = str_len(arr_1);

  for (int count = 0; arr_1[count] != '\0'; count++) {
    arr_concat[count] = arr_1[count];
  }

  for (int count = 0; arr_2[count] != '\0'; count++) {
    arr_concat[count + length_of_arr_1] = arr_2[count];
  }

  printf("The concatenated string is: %s \n", arr_concat);
}
*/

// 5. String Tokenization: Create a program that tokenizes a given string into words. Each word should be printed on a separate line.

/*
#include <stdio.h>

int main () {
  char arr[50];

  printf("Enter a string: ");
  scanf("%[^\n]", arr);

  fflush(stdin);

  printf("\n");
  for (int count = 0; arr[count] != '\0'; count++) {
    printf("%c", arr[count]);
    (arr[count] == ' ') ? printf("\n") : printf("");
  }
  printf("\n");
}
*/

// 6. Substring Search: Write a program to find all occurrences of a substring within a given string.

#include <stdio.h>

int str_len(char arr[]) {
  int length_of_arr = 0;
  for(int count = 0; arr[count] != '\0'; count++) {
    length_of_arr++;
  }
  return length_of_arr;
}

int main () {
  char arr[50];
  char substring[50];

  printf("Enter the string: ");
  scanf("%[^\n]", arr);

  fflush(stdin);

  printf("Enter the substring to be searched: ");
  scanf("%[^\n]", substring);

  int length_of_arr = str_len(arr);
  int length_of_substring = str_len(substring);

  int placeholders[50] = {0};
  int counter = 0;

  for(int count = 0; count < length_of_arr; count++) {
    for(int substring_count = 0; substring_count < length_of_substring; substring_count++) {
      if (arr[count + substring_count] == substring[substring_count]) {
        counter++;
      }
      if (counter == length_of_substring) {
        placeholders[count] = count + 1;
        break;
      }
    }
  }

  printf("In %s, the substring occurs at: ", arr);

  for(int count = 0; count < length_of_arr; count++) {
    if (count != 0) {
      printf("%d ", count);
    } else {
      printf("");
    }
  }
}
