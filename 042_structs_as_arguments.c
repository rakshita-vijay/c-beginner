#include <stdio.h>
#include <string.h>

struct student {
  char first_name[20];
  char last_name[20];
  };

void get_info (struct student *st) {
  // int str_len = 20;
  char info[] = "";

  printf("Enter your first name: ");
  scanf("%s", info);
  st->first_name = (char *) malloc(strlen(info) + 1); // A->B = (*A).B ; +1 for the null character
  strcopy(st->first_name, info);

  printf("Enter your last name: ");
  scanf("%s", info);
  st->last_name = (char *) malloc(strlen(info) + 1); // A->B = (*A).B ; +1 for the null character
  strcopy(st->last_name, info);
}

int main () {
  struct student *student1;

  get_info(*student1);

  printf("First name: %s", student1->first_name);
  printf("Last name: %s", student1->last_name);
}
