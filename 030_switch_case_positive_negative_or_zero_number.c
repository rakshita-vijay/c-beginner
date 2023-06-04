// Number: Positive/Negative/Zero

#include <stdio.h>

int main()
{
    int num;

    printf("Enter the number to check: ");
    scanf("%i", &num);

    switch(num>=0)
    {
        case 1: // 1 = True
        {
            switch(num>0)
            {
                case 1:
                {
                    printf("The number, %i, is Positive", num);
                    break;
                }
                case 0:
                {
                    printf("The number entered is Zero", num);
                    break;
                }
            }
            break;
        }
        case 0: // 0 = False
        {
            printf("The number, %i, is Negative", num);
            break;
        }
    }
}
