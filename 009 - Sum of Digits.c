#include <stdio.h>

int main()
{
    int value = 0;
    int originalValue = 0;
    int sum = 0;
    
    printf("Enter the number: ");
    scanf("%i", &value);
    originalValue = value;
    
    for( ; value != 0 ; value /= 10)
    {
        sum += (value % 10);
    }
    
    printf("The sum of the digits of %i is %i", originalValue, sum);
}
