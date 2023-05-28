#include <stdio.h>

int main() 
{
    char nam[100];
    
    printf("Enter your name: "); 
    scanf("%s", nam); 
    printf("\n");
    
    printf("Hi, my name is %s", nam);
}
