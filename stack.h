#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

typedef struct stack{
    int c;
    stack * next;

} stack;

stack * add_element(stack * head, int val);
int read_element(stack * head);
stack * delete_element(stack * head);
void delete_stack(stack * head);

int braces(char * string, int size);
int find_min(int val, int * arr, int size);
