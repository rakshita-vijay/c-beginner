#include <stdio.h>

int main () {
  static long num;
  printf("Call number: %ld \n", num++);
  main();
  return 0;
}
