#pragma once

typedef struct {
    struct node * list;
} stack;

stack * init_stack();
stack * push(stack* , int);
int pop(stack*);
int peek(stack*);
void display_stack(stack *);
void destroy_stack(stack *);