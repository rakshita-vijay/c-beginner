// Q1

// #include <stdio.h>
// #include <string.h>

// void str_cut_cat(char arr[], int index_to_cat) {
//   int count;
//   for(count = index_to_cat; arr[count] != '\0'; count++) {
//     arr[count] = arr[count + 2];
//   }
//   arr[count] = '\0';
// }

// int main () {
//   char arr_1[20];
//   char arr_2[20];

//   printf("Enter the first string with random hashes: ");
//   scanf("%s", arr_1);
//   printf("Enter the second string with random hashes: ");
//   scanf("%s", arr_2);

//   int length_of_arr_1 = strlen(arr_1);
//   int length_of_arr_2 = strlen(arr_2);

//   // removing hashes and previous letter from arr_1
//   int count;
//   for(count = 0; count < length_of_arr_1; count++) {
//     while (arr_1[count] == '#') {
//       for(int count = 0; count < length_of_arr_1; count++) {
//         if (arr_1[count] == '#') {
//           str_cut_cat(arr_1, count - 1);
//         }
//       }
//     }
//     // count--;
//   }
//   arr_1[count] = '\0';
//   // removing hashes and previous letter from arr_2
//   for(count = 0; count < length_of_arr_2; count++) {
//     while (arr_2[count] == '#') {
//       for(int count = 0; count < length_of_arr_2; count++) {
//         if (arr_2[count] == '#') {
//           str_cut_cat(arr_2, count - 1);
//         }
//       }
//     }
//     // count--;
//   }
//   arr_2[count] = '\0';

//   printf("arr_1: %s \n", arr_1);
//   printf("arr_2: %s \n", arr_2);

//   // comparing
//   if (strlen(arr_1) != strlen(arr_2)) {
//     printf("Not equal :( \n");
//   } else {
//     for (int counter = 0; counter < strlen(arr_1); counter++) {
//       if (arr_1[counter] == arr_2[counter]){
//         continue;
//       } else {
//         printf("Not equal :( \n");
//         break;
//       }
//     }
//     printf("Equal :) \n");
//   }
// }


// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

// Q2

#include <stdio.h>
#include <string.h>

int main () {
  int num_of_strings;
  printf("Enter the number of strings: ");
  scanf("%d", &num_of_strings);
  printf("\n");

  char arr[20];
  int length_of_arr;
  int counter = 1;

  for (int string_number = 0; string_number < num_of_strings; string_number++) {
    printf("Enter string #%i [end of string is considered a backslash]: ", string_number + 1);
    scanf("%s", arr);

    length_of_arr = strlen(arr);

    for (int holder = 0; holder < length_of_arr; holder++) {
      for (int index = holder + 1; index < length_of_arr; index++) {
        if (arr[holder] == arr[index]) {
          counter++;
        }
        if (counter > 2) {
          break;
        }
      }
      if (counter > 2) {
        printf("%i %s \n", holder, arr);
        break;
      } else {
        counter = 1;
      }
    }
    printf("\n");
  }
}
