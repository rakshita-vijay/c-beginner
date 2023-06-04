#include <stdio.h>

// strnlen, strncat, strncmp

int strnLen(char str[]) // str is a character array
{
    int count = 0;

    for(count; str[count] != '\0';)
    {
        count++;
    }

    return count;
}

void strnCat(char str1[], char str2[]) // str1, str2 are character arrays
{
    int count;
    int strnLenRes1 = strnLen(str1);
    int strnLenRes2 = strnLen(str2);
    int strnLenRes = strnLenRes1 + strnLenRes2;
    char res[strnLenRes];

    for(count = 0; count < strnLenRes1; count++)
    {
        res[count] = str1[count];
        // printf("%i %c \n", count, res[count]);
    }

    for(count = strnLenRes1; count <= strnLenRes; count++)
    {
        res[count] = str2[count - strnLenRes1];
        // printf("%i %c \n", count, res[count]);
    }

    for (count = 0; count < strnLenRes, res[count] != '\0'; count++)
    {
        printf("%c", res[count]);
    }
}


void strnCmp(char str1[], char str2[]) // str1, str2 are character arrays
{
    int count;
    int Len = ((strnLen(str1) < strnLen(str2)) ? strnLen(str1) : strnLen(str2));
    char res[Len];

    for(count = 0; count < Len; count++)
    {
        if (str1[count]==str2[count])
        {
            res[count] = str1[count];
        }
        else
        {
            continue;
        }
    }

    /*
    int index1;
    int index2;

    for(index1 = 0; index1 < Len, str1[count] != '\0'; index1++)
    {
        for()
    }
    */

    res[count] = '\0';

    for (count = 0; res[count] != '\0'; count++)
    {
            printf("%c", res[count]);
    }
}


int main()
{
    char string1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    int strnLenRes1 = strnLen(string1);
    printf("The length of the entered character array \'%s\' is: %d \n", string1, strnLenRes1);

    char string2[] = {'a', 'b', 'c', 'f', 'g', 'h', 'i', 'd', '\0'};
    int strnLenRes2 = strnLen(string2);
    printf("The length of the entered character array \'%s\' is: %d \n", string2, strnLenRes2);

    printf("The concatenated array of the entered character arrays \'%s\' and \'%s\' is: ", string1, string2);
    strnCat(string1, string2);

    printf("\n");

    printf("The entered character arrays \'%s\' and \'%s\' have been compared and the characters present in both in order are: ", string1, string2);
    strnCmp(string1, string2);
}
