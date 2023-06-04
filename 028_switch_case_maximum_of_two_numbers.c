// Maximum of 2 Numbers

#include <stdio.h>

int main()
{
    int num1;
    int num2;

    printf("Enter the first number: ");
    scanf("%i", &num1);
    printf("Enter the second number: ");
    scanf("%i", &num2);

    switch(num1>num2)
    {
        case 1:
        {
            printf("%i (num1) is greater than %i (num2)", num1, num2);
            break;
        }
        case 0:
        {
            printf("%i (num2) is greater than %i (num1)", num2, num1);
            break;
        }
        default:
        {
            printf("%i (num1) is equal to %i (num2)", num1, num2);
        }
    }
}
