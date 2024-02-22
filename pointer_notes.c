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
*p = 8;  // a = 8 ---> dereferencing
print a;  // 8


int num = 5;
int *p1 = &num;
char alph = 'c';
char *p2 = &alph;

p = p+1 increments the pointer address by 4 bytes
*p = (*p) + 1 increments the value at the address stored in p by 1;

Address : &A[i] or (A + i)  // simply using A gives base address
Value : A[i] or *(A + i)

int *A and int A[] are same in function definition

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

const int *p_num // value cannot be changed using pointer; pointer address can be changed; integer variable can be changed directly (without using pointer)
int *const p_num // pointer address cannot be changed
const int *const p_num // both value and pointer address cannot be changed; num cna still be changed directly

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

malloc() - allocates a single block of memory
calloc() - allocates multiple blocks of memory
realloc() - reallocates memory allocated to malloc() or calloc() functions

malloc - void* malloc (size_t size)  // size to be allocated; initially, in the memory blocks, all are pre-existing, garbage values
calloc - void* calloc (size_t num, size_t size)  // number of elements of data type, size of data type; initially, in the memory blocks, all values are initialized to zero
realloc - void* realloc (void *ptr, size_t size)  // pointer to previously assigned memory block, size of new block - new can be > old block size. if so, either immediately subsequent memory is allotted or it is allotted in a totally new place

void *p = malloc(4);
void *p = malloc(sizeof(int));
void *p = malloc(10 * sizeof(int));

int *p = (int *)malloc(3 * sizeof(int))

int *p = (int *)calloc(3, sizeof(int))

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

arr[i] = *(arr + i)

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
