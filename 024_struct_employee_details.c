// Accept and Display Employee Details

#include <stdio.h>

struct employee {
  char name[50];
  char dob[12];
  char doj[12];
  char qualification[50];
  char jobDesc[50];
};

struct employee getEmployeeDetails() {
  struct employee empNo;

  printf("1> Name: ");
  scanf("%s", empNo.name);
  printf("\n");

  printf("2> Date of Birth: ");
  scanf("%s", empNo.dob);
  printf("\n");

  printf("3> Date of Join: ");
  scanf("%s", empNo.doj);
  printf("\n");

  printf("4> Qualification: ");
  scanf("%s", empNo.qualification);
  printf("\n");

  printf("5> Job Description: ");
  scanf("%s", empNo.jobDesc);
  printf("\n \n");

  return empNo;
}

int main() {
  int numberOfEmployees;

  printf("Enter the number of employees: ");
  scanf("%i", &numberOfEmployees);

  struct employee emp[numberOfEmployees];

  for (int employeeNumber = 0; employeeNumber < numberOfEmployees; employeeNumber++) {
    printf("For employee number (%i), enter details: \n", (employeeNumber + 1));
    emp[employeeNumber] = getEmployeeDetails();
  }

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  printf("Entered details are: \n");

  for (int employeeNumber = 0; employeeNumber < numberOfEmployees; employeeNumber++) {
    printf("Employee Number (%i): \n", (employeeNumber + 1));
    printf("1> Name: %s \n", emp[employeeNumber].name);
    printf("2> Date of Birth: %s \n", emp[employeeNumber].dob);
    printf("3> Date of Join: %s \n", emp[employeeNumber].doj);
    printf("4> Qualification: %s \n", emp[employeeNumber].qualification);
    printf("5> Job Description: %s \n \n", emp[employeeNumber].jobDesc);
  }
}
