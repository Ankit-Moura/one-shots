#include <stdio.h>
#include "../../linked_list/lib/singly_linked_list.h"
#include "stack_ll.h"
#include <stdlib.h>


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