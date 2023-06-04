// Day of Week Name

#include <stdio.h>

int main()
{
    int dayNumber;

    printf("Enter the number of the day you want to print (1-7): ");
    scanf("%i", &dayNumber);

    switch(dayNumber)
    {
        case 1:
        {
            printf("Sunday");
            break;
        }
        case 2:
        {
            printf("Monday \n");
            break;
        }
        case 3:
        {
            printf("Tuesday \n");
            break;
        }
        case 4:
        {
            printf("Wednesday \n");
            break;
        }
        case 5:
        {
            printf("Thursday \n");
            break;
        }
        case 6:
        {
            printf("Friday \n");
            break;
        }
        case 7:
        {
            printf("Saturday \n");
            break;
        }
        default:
        {
            printf("Error. You have chosen a number out of bounds.\n");
        }
    }
}
