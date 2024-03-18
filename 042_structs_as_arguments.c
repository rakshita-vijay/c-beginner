#include <stdio.h>
#include <string.h>

struct student {
  char first_name[20];
  char last_name[20];
  };

void get_info (struct student *st) {
  // int str_len = 20;
  char info[20] = "";

  printf("Enter your first name: ");
  scanf("%s", info);
  printf("strlen(info) = %lu", strlen(info));
  st->first_name = (char *) malloc(strlen(info) + 1); // A->B = (*A).B ; +1 for the null character
  strcpy(st->first_name, info);

  printf("Enter your last name: ");
  scanf("%s", info);
  st->last_name = (char *) malloc(strlen(info) + 1); // A->B = (*A).B ; +1 for the null character
  strcpy(st->last_name, info);
}

int main () {
  struct student *student1;

  get_info(student1);

  printf("First name: %s", student1->first_name);
  printf("Last name: %s", student1->last_name);
}
