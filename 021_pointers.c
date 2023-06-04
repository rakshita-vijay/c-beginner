#include <stdio.h>

int main()
{
    int num = 10;
    int *pnum = &num;

    printf("Address of pointer/Memory location of variable num: %p \n", &pnum);
    printf("Value of pointer: %p \n", pnum);
    printf("Value of what pointer is pointing to: %i \n", *pnum);
}
