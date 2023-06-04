#include <stdio.h>

int main()
{
    int numberOfLines = 0;
    
    printf("Enter the number of lines to print: ");
    scanf("%i", &numberOfLines);
    
    char alphabets[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    for(int lineNumber = 0 ; lineNumber < numberOfLines ; lineNumber++)
    {
        for(int numberOfSpaces = 0 ; numberOfSpaces < (numberOfLines-lineNumber) ; numberOfSpaces++)
        {
            printf(" ");
        }
        
        for(int numberOfAlphabets = 0 ; numberOfAlphabets <= lineNumber ; numberOfAlphabets++)
        {
            printf("%c", alphabets[numberOfAlphabets]);
        }
        
        for(int numberOfAlphabets = lineNumber-1 ; numberOfAlphabets >= 0 ; numberOfAlphabets--)
        {
            printf("%c", alphabets[numberOfAlphabets]);
        }
        
        printf("\n");
    }
}
