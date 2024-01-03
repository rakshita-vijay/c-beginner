#include <stdbool.h>

bool validate(long digits) {

  int size_of_digits = 0;
  long copy_of_digits = digits;
  while (copy_of_digits > 0) {
    copy_of_digits /= 10;
    size_of_digits++;
  }

  char arr[size_of_digits];

  int num = 0;
  for (long index = sizeof(digits) - 1; index >= 0 ; index--) {
    num = digits % 10;
    arr[index] = num;
  }

  long sum = 0;
  for (long index = (sizeof(arr)-2); index >= 0; index -= 2) {
    arr[index] *= 2;
    while (arr[index] > 9) {
      arr[index] -= 9;
    }
    sum += arr[index];
  }
  if ((sum % 10) == 0) {
    return true;
  } else {
    return false;
  }
}

void main(){
  bool result = validate(123);
  printf("%i", (int) result);
}
