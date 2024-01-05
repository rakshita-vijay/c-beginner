Pointer Notes

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

pointers store memory address of another variable

int - 4 bytes
float - 4 bytes
char - 1 byte

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

int a = 5;
int *p;

Ways of relating:
int *p = &a;
*p = a;  // *p stores the value at a
p = &a;  // p stores the address of a

print p;  // prints address of a
printf *p;  // prints value of a ---> dereferencing
print &p;  // prints address of p
print a;  // prints value of a
print &a;  // prints address of a (& = address)

if you do:
*p = 8;  // a = 8
print a;  // 8


int num = 5;
int *p1 = &num;
char alph = 'c';
char *p2 = &alph;
