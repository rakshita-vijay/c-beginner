#include <stdio.h>

int main() {
  int a;
  float b;
  short c;
  long d;
  double e;
  long long f;
  long double g;
  char h;

  printf("a is of size: %i \n", sizeof(a));
  printf("b is of size: %i \n", sizeof(b));
  printf("c is of size: %i \n", sizeof(c));
  printf("d is of size: %i \n", sizeof(d));
  printf("e is of size: %i \n", sizeof(e));
  printf("f is of size: %i \n", sizeof(f));
  printf("g is of size: %i \n", sizeof(g));
  printf("h is of size: %i \n", sizeof(h));
}
