// with functions

#include <stdio.h>

struct employee {
  char employeeName[50];
  char employeeDateOfJoin[20];
  float employeeSalary;
};

void getDataFromUser(int employeeNumber);
void printDataObtainedFromUser(int employeeNumber, char employeeName[50], char employeeDateOfJoin[20], float employeeSalary);

void getDataFromUser(int employeeNumber) {
  struct employee emp;

  printf("Enter Name of Employee Number %i: ", employeeNumber);
  scanf("%s", emp.employeeName);
  // printf("\n");

  printf("Enter Date of Join of Employee Number %i: ", employeeNumber);
  scanf("%s", emp.employeeDateOfJoin);
  // printf("\n");

  printf("Enter Salary of Employee Number %i: ", employeeNumber);
  scanf("%f", &emp.employeeSalary);
  // printf("\n");

  printDataObtainedFromUser(employeeNumber, emp.employeeName, emp.employeeDateOfJoin, emp.employeeSalary);
}

void printDataObtainedFromUser(int employeeNumber, char employeeName[50], char employeeDateOfJoin[20], float employeeSalary) {
  printf("\nDETAILS OF EMPLOYEE NUMBER %i: \n", employeeNumber);
  printf("1> Name: %s \n2> Date of Join: %s\n3> Salary: %f \n", employeeName, employeeDateOfJoin, employeeSalary);
  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}

int main() {
  int noOfEmployees = 0;
  int employeeNumber;
  char employeeName[50];
  char employeeDateOfJoin[12];
  float employeeSalary;

  printf("Enter the number of employees: ");
  scanf("%i", &noOfEmployees);
  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  for (employeeNumber = 1; employeeNumber <= noOfEmployees; employeeNumber++) {
    getDataFromUser(employeeNumber);
  }
}
