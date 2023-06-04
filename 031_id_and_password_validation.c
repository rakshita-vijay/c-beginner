// ID and Password Validation

#include <stdio.h>

int main()
{
    int id;
    char passwrd[10];
    int idToCheck;
    char passwrdToCheck[10];

    printf("Enter your ID number: ");
    scanf("%i", &id);

    printf("Enter your password: ");
    scanf("%s", passwrd);

    printf("\n Login Page: \n");

    printf("Enter ID number: ");
    scanf("%i", &idToCheck);

    printf("Enter password: ");
    scanf("%s", passwrdToCheck);

    switch(idToCheck==id)
    {
        case 1: // 1 = True
        {
            break;
        }
        case 0: // 0 = False
        {
            printf("The entered ID is wrong. Please re-enter it. \n");
            break;
        }
    }

    for(int index = 0 ; index < 10 ; index++)
    {
        switch(passwrdToCheck[index]==passwrd[index])
        {
            case 1: // 1 = True
            {
                break;
            }
            case 0: // 0 = False
            {
                printf("The entered password is wrong. Please re-enter it. \n");
                break;
            }
        }
        break;
    }
}
