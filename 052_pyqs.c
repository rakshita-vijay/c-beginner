#include <stdio.h>
#include <string.h>

void str_cut_cat(char arr[], int index_to_cat) {
  int count;
  for(count = index_to_cat; arr[count] != '\0'; count++) {
    arr[count] = arr[count + 2];
  }
  arr[count] = '\0';
}

int main () {
  char arr_1[20];
  char arr_2[20];

  printf("Enter the first string with random hashes: ");
  scanf("%s", arr_1);
  printf("Enter the second string with random hashes: ");
  scanf("%s", arr_2);

  int length_of_arr_1 = strlen(arr_1);
  int length_of_arr_2 = strlen(arr_2);

  // removing hashes and previous letter from arr_1
  int count;
  for(count = 0; count < length_of_arr_1; count++) {
    while (arr_1[count] == '#') {
      for(int count = 0; count < length_of_arr_1; count++) {
        if (arr_1[count] == '#') {
          str_cut_cat(arr_1, count - 1);
        }
      }
    }
    // count--;
  }
  arr_1[count] = '\0';
  // removing hashes and previous letter from arr_2
  for(count = 0; count < length_of_arr_2; count++) {
    while (arr_2[count] == '#') {
      for(int count = 0; count < length_of_arr_2; count++) {
        if (arr_2[count] == '#') {
          str_cut_cat(arr_2, count - 1);
        }
      }
    }
    // count--;
  }
  arr_2[count] = '\0';

  printf("arr_1: %s \n", arr_1);
  printf("arr_2: %s \n", arr_2);

  // comparing
  if (strlen(arr_1) != strlen(arr_2)) {
    printf("Not equal :( \n");
  } else {
    for (int counter = 0; counter < strlen(arr_1); counter++) {
      if (arr_1[counter] == arr_2[counter]){
        continue;
      } else {
        printf("Not equal :( \n");
        break;
      }
    }
    printf("Equal :) \n");
  }
}
