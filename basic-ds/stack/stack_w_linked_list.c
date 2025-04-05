#include <stdio.h>
#include "./../linked_list/lib/singly_linked_list.h"
#include <stdlib.h>

typedef struct {
    struct node * list;
} stack;

stack * init_stack();
stack * push(stack* , int);
int pop(stack*);
int peek(stack*);
void display_stack(stack *);
void destroy_stack(stack *);

int main(){
    stack *s = init_stack();
    s = push(s, 10);
    s = push(s, 20);
    s = push(s, 30);
    s = push(s, 40);
    s = push(s, 50);
    s = push(s, 60);
    display_stack(s);
    printf("popped -> %d\n", pop(s));
    printf("popped -> %d\n", pop(s));
    printf("peek -> %d\n", peek(s));
    s = push(s, 99);
    display_stack(s);
    destroy_stack(s);
}

stack * init_stack(){
    stack * s = (stack *)malloc(sizeof(stack));
    if (!s) {
        printf("overflow condition\n");
        return NULL;
    }
    return s;
}

stack * push(stack * s, int data){
    if(!s) {
        return NULL;
    }
    s->list = insert_node(s->list, data, 0);
    return s;
}

int pop(stack *s){
    if(!s){
        return -1;
    }
    if(!s->list){
        printf("underflow condition stack is empty\n");
        return -1;
    }
    int data = s->list->data;
    s->list = delete_node(s->list, data);
    return data;
}

int peek(stack * s){
    if(!s || !s->list){
        return -1;
    }
    return s->list->data;
}

void display_stack(stack * s){
    struct node * temp ;
    if(!s || !s->list){
        return;
    }
    temp = s->list;
    while (temp)
    {
        printf("| %d |\n", temp->data);
        printf("_____\n");
        temp = temp->link;
    }
    return;
}

void destroy_stack(stack * s){
    if(!s){
        return;
    }
    delete_linked_list(s->list);
    free(s);
    return;
}