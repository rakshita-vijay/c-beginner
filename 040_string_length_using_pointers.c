#include <stdio.h>

int string_length(const char *p_arr) {
  const char *p_array = p_arr;
  // while (p_arr != (void *)0) {
  while (*p_arr != '\0') {
    p_array++;
  }
  return p_array - p_arr;
}

int main() {
  char arr[] = "";
  printf("Enter a string: ");
  scanf("%s", arr);
  printf("The string is: %s \n", arr);
  const char *p_arr = arr;

  int count = string_length(p_arr);
  printf("The length of %s is: %i \n", arr, count);
}
