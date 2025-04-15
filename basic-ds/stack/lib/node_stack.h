#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../../tree/binary_tree.h"
typedef struct{
    struct b_node ** arr;
    int top;
    int size;
} stack;

stack * init_stack(size_t size);
stack * push(stack* , struct b_node *);
struct b_node * pop(stack*);
int peek(stack*);
void display_stack(stack *);
void destroy_Stack(stack *);