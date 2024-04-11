// 1. Factorial Calculation: Write a program to calculate the factorial of a non-negative integer using recursion

/*
#include <stdio.h>

int fact(int num) {
  return (num == 1) ? 1 : (num * fact(num - 1));
}

int main () {
  int num;
  printf("Enter the number you want to get the factorial of: ");
  scanf("%d", &num);

  printf("The factorial of %d is: %d \n", num, fact(num));
}
*/

// 2. Fibonacci Series: Write a program to print the Fibonacci series up to a given number of terms using recursion.

/*
#include <stdio.h>

void fibonacci(int fibonacci_series[], int index, int number_of_terms) {
  if (index < number_of_terms) {
    fibonacci_series[index] = fibonacci_series[index - 1] + fibonacci_series[index - 2];
    fibonacci(fibonacci_series, index + 1, number_of_terms);
  } else {
    printf("Fibonacci Series calculation completed :) \n \n");
  }
}

int main () {
  int num_1;
  int num_2;
  int number_of_terms;

  printf("Enter the first digit of the Fibonacci Series you want: ");
  scanf("%d", &num_1);
  printf("Enter the second digit of the Fibonacci Series you want: ");
  scanf("%d", &num_2);
  printf("Enter the number of terms of the Fibonacci Series to be printed: ");
  scanf("%d", &number_of_terms);
  printf("\n");

  int fibonacci_series[] = {num_1, num_2};

  fibonacci(fibonacci_series, 2, number_of_terms);

  printf("The Fibonacci Series is: ");
  for (int count = 0; count < number_of_terms; count++) {
    printf("%3d  ", fibonacci_series[count]);
  }
  printf("\n");
}
*/

// 3. Sum of Digits: Write a program to find the sum of digits of a positive integer using recursion.

/*
#include <stdio.h>

int sum_of_digits = 0;

int digit_sum(int num) {
  return (num == 0) ? 0 : (num % 10 + digit_sum(num / 10));
}

int main () {
  int num;

  printf("Enter the number for which sum of digits has to be found: ");
  scanf("%d", &num);

  sum_of_digits = digit_sum(num);

  printf("Sum of digits of %d is: %d \n", num, sum_of_digits);
}
*/

// 4. Power Calculation: Write a program to calculate the power of a number using recursion.

/*
#include <stdio.h>

int num_power(int num, int count, int power) {
  return (count > power) ? 1 : (num * num_power(num, count + 1, power));
}

int main () {
  int num;
  int power;

  printf("Enter the number for which power has to be found: ");
  scanf("%d", &num);
  printf("Enter the power: ");
  scanf("%d", &power);

  int power_of_num = num_power(num, 1, power);

  printf("%d to the power of %d is: %d \n", num, power, power_of_num);
}
*/

// 5. Binary Search: Write a program to perform binary search on a sorted array using recursion.

#include <stdio.h>
#include <math.h>

int res = 0; // no/false

void binary_search(int num_to_search, int arr[], int start_index, int end_index) {
  int halfway_mark = start_index + (int)ceil((end_index - start_index) / 2);
  if (num_to_search < arr[halfway_mark]) {
    binary_search(num_to_search, arr, start_index, halfway_mark);
  } else if (num_to_search > arr[halfway_mark]) {
    binary_search(num_to_search, arr, halfway_mark, end_index);
  }
  if (num_to_search == arr[start_index]) {
    res = start_index;
  } else if (num_to_search == arr[end_index]) {
    res = end_index;
  }
}

int main (){
  int num_of_elements;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &num_of_elements);

  int temp = 0;
  printf("\n");

  int arr[num_of_elements];
  printf("Enter the elements of the array: \n");
  for (int count = 0; count < num_of_elements; count++) {
    printf("Element #%d: ", count + 1);
    scanf("%d", &arr[count]);
    if (count == 0) {
      continue;
    } else {
      if (arr[count - 1] > arr[count]) {
        temp = arr[count - 1];
        arr[count - 1] = arr[count];
        arr[count] = temp;
      }
    }
  }

  printf("\n");

  // for (int count = 0; count < num_of_elements; count++) {
  //   printf("Element #%d: %d \n", count + 1, arr[count]);
  // }

  int num_to_search;

  printf("Enter the number to search: ");
  scanf("%d", &num_to_search);

  printf("\n");

  binary_search(num_to_search, arr, 0, (num_of_elements - 1));
  printf("res: %d \n", res);
}
