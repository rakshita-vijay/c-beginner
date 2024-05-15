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
