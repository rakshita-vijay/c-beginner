/*

O/P:
*****
****
***
**
*

*/

#include <stdio.h>
#include <math.h>

int main() 
{
    int numberOfLines;
    int lineCount;
    int indexOfCharInLine;
    
    printf("Enter the number of lines you want the pattern to be printed in: ");
    scanf("%i", &numberOfLines);

    for(lineCount = 0; lineCount <= numberOfLines; lineCount++)
    {
        for(indexOfCharInLine = (numberOfLines-lineCount); indexOfCharInLine >= 1; indexOfCharInLine--)
        {
            printf("*");
        }
        printf("\n");
    }
}
