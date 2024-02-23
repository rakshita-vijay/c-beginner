#include <stdio.h>
#include <stdlib.h>

int string_length(const char *string) {
  const char *lastAddress = string;

  while (*lastAddress) {
    ++lastAddress;
  }

  return lastAddress - string;
}

int main() {
  char arr[] = "";
  printf("Enter a string: ");
  scanf("%s", arr);

  printf("The length of '%s' is: %d \n", arr, string_length(arr));
  printf("The length of '%s' is: %d \n", "rakshita", string_length("rakshita"));
  printf("The length of '%s' is: %d \n", "", string_length(""));

  return 0;
}
