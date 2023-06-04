// without functions

#include <stdio.h>
#include <string.h>

struct employee
{
    char name[50];
    char dateOfJoin[20];
    float salary;
};

int main()
{
    struct employee No1 = {"David", "17-02-2006", 1234567890};

    printf("Name of Employee: %s \n", No1.name);
    printf("Date of Join of Employee: %s \n", No1.dateOfJoin);
    printf("Salary of Employee: %f \n", No1.salary);

    struct employee No2 = {"", "", 0.0};

    printf("Enter data: \n");

    printf("Name: ");
    scanf("%s", No2.name);
    printf("\n");

    printf("Date of Join: ");
    scanf("%s", No2.dateOfJoin);
    printf("\n");

    printf("Salary: ");
    scanf("%f", &No2.salary);
    printf("\n");

    printf("Name of Employee: %s \n", No2.name);
    printf("Date of Join of Employee: %s \n", No2.dateOfJoin);
    printf("Salary of Employee: %f \n", No2.salary);
}
