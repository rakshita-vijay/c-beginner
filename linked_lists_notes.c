linked lists:
collection of nodes
each has pointers to other nodes
a node is represented by a structure

struct node {
  int data;
  struct node *next;
}

dynamic, no memory wastage
insertion and deletion operations are faster
need more memory to store addresses

ordinary pointer variable points to the first node in the list
if list is empty it can be assigned NULL

struct node *head = NULL;

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

r : reading only.
    if file opened successfully, pointer points to the first character in it.
    if file cannot be opened, returns NULL.

w : writing only.
    contents are overwritten.
    if file doesn’t exist, a new file is created.
    if file cannot be opened, returns NULL.

a : appending only.
    if file opened successfully, pointer points to the last character in it.
    if file doesn’t exist, a new file is created.
    if file cannot be opened, returns NULL.

r+

Searches file. Opens the file for both reading and writing. If opened successfully, fopen() loads it into memory and sets up a pointer that points to the first character in it. Returns NULL, if unable to open the file.

w+

Searches file. If the file exists, its contents are overwritten. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. The difference between w and w+ is that we can also read the file created using w+.

a+

Searches file. If the file is opened successfully fopen( ) loads it into memory and sets up a pointer that points to the last character in it. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. The file is opened for reading and appending(writing at the end of the file).
rb

Open the binary file in read mode. If the file does not exist, the open() function returns NULL.

wb

Open the binary file in write mode. As the pointer is set to the start of the file, the contents are overwritten. If the file does not exist, a new file is created.

ab

Open the binary file in append mode. The file pointer is set after the last character in the file. A new file is created if no file exists with the name.

rb+

Open the binary file in read and write mode. If the file does not exist, the open() function returns NULL.

wb+

Open the binary file in read and write mode. Contents are overwritten if the file exists. It will be created if the file does not exist.

ab+

Open the binary file in read and append mode. A file will be created if the file does not exist.
