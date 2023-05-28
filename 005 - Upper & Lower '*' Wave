#include <stdio.h>
#include <math.h>

int main() 
{
    int numberOfLines;
    int lineCount;
    int indexOfCharInLine;
    
    printf("Enter the number of lines you want the pattern to be printed in: ");
    scanf("%i", &numberOfLines);
    
    for(lineCount = 1; lineCount <= ((ceil(numberOfLines/2))+1); lineCount++)
    {
        for(indexOfCharInLine = 1; indexOfCharInLine <= lineCount; indexOfCharInLine++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    for(lineCount = ((ceil(numberOfLines/2))+1); lineCount <= numberOfLines; lineCount++)
    {
        for(indexOfCharInLine = (numberOfLines-lineCount); indexOfCharInLine >= 1; indexOfCharInLine--)
        {
            printf("*");
        }
        printf("\n");
    }
}

/*

O/P:
*
**
***
****
***
**
*

*/
