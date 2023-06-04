// unlinked functions

#include <stdio.h>
#include <math.h>

// gcd of two numbers
int gcd(int num1, int num2)
{
    int factor = 1;
    int gcd = 1;

    printf("The numbers entered are: %d and %d \n", num1, num2);

    if (num1<0)
    {
        num1 = -num1;
    }
    if (num2<0)
    {
        num2 = -num2;
    }

    for (factor = 1; factor<=num1 && factor<=num2; factor++)
    {
        if (num1%factor==0 && num2%factor==0)
        {
            gcd = factor;
        }
    }

    printf("The greatest common divisor of the numbers entered is: %i \n", gcd);
}

// absolute value of one number
float absValue(float num)
{
    float absNum;

    absNum = num;

    if (num<0)
    {
        absNum = -num;
    }

    printf("The number entered is: %f \n", num);
    printf("The absolute value of the number entered is: %f \n", absNum);
}

// square root of one number
float sqRoot(float num)
{
    float absNum;
    float sqRootOfNum;

    absNum = num;

    if (num<0)
    {
        absNum = -num;
        printf("The number entered is: %f \n", num);
        printf("The absolute value of the number entered is: %f \n", absNum);

        sqRootOfNum = sqrt(absNum);
        printf("The square root of the number entered is: %fi \n", sqRootOfNum);
    }

    else
    {
        printf("The number entered is: %f \n", num);
        printf("The absolute value of the number entered is: %f \n", absNum);

        sqRootOfNum = sqrt(absNum);
        printf("The square root of the number entered is: %f \n", sqRootOfNum);
    }
}

int main()
{
    printf("To find the gcd: \n");
    gcd(-7, -36); // checked, working correctly - unlinked

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    printf("To find the absolute value: \n");
    absValue(-34.5); // checked, working correctly - unlinked

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    printf("To find the square root: \n");
    sqRoot(-45.6); // checked, working correctly - unlinked
}
