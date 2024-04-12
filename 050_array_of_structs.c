#include <stdio.h>
#include <string.h>
#include <math.h>

struct student {
  char name[50];
  int ID_number;
  float agg_marks;
};

int main() {
  int num_of_students;
  printf("Enter the number of students: ");
  scanf("%d", &num_of_students);
  getchar();
  printf("\n");

  struct student stud_arr[num_of_students];

  // getting user_input
  for (int count = 0; count < num_of_students; count++) {
    printf("Enter student #%d's name: ", count + 1);
    scanf("%[^\n]", stud_arr[count].name);
    getchar();

    printf("Enter student #%d's ID number: ", count + 1);
    scanf("%d", &stud_arr[count].ID_number);

    printf("Enter student #%d's aggregate marks: ", count + 1);
    scanf("%f", &stud_arr[count].agg_marks);
    printf("\n");
    getchar();
  }

  // printing user_input in form of a table
  int length_of_max_name = 0;
  for (int count = 0; count < num_of_students; count++) {
    if (strlen(stud_arr[count].name) > length_of_max_name) {
      length_of_max_name = strlen(stud_arr[count].name);
    }
  }

  printf("length_of_max_name = %d\n", length_of_max_name);

  for (int counter = 0; counter < (int) (length_of_max_name - strlen("Name")); counter++) {
    printf(" ");
  }
  printf("Name");
  for (int counter = 0; counter < (int) (length_of_max_name - strlen("ID number")); counter++) {
    printf(" ");
  }
  printf("ID number");
  for (int counter = 0; counter < 6; counter++) {
    printf(" ");
  }
  printf("Aggregate Marks");
  printf("\n");

  for (int count = 0; count < num_of_students; count++) {
    for (int counter = 0; counter < (int) (length_of_max_name - strlen(stud_arr[count].name)); counter++) {
      printf(" ");
    }
    printf("%s", stud_arr[count].name);
    for (int counter = 0; counter < (int) (length_of_max_name + strlen("ID number") - log10(stud_arr[count].ID_number) + 1); counter++) {
      printf(" ");
    }
    printf("%i", stud_arr[count].ID_number);
    for (int counter = 0; counter < (int) (strlen("  Aggregate Marks") - log10(stud_arr[count].agg_marks) + 1); counter++) {
      printf(" ");
    }
    printf("%f", stud_arr[count].agg_marks);
    printf("\n");
  }
}
