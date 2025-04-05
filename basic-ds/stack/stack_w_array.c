#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int * arr;
    int top;
    int size;
} stack;

stack * init_stack(size_t size);
stack * push(stack* , int);
int pop(stack*);
int peek(stack*);
void display_stack(stack *);
void destroy_Stack(stack *);
int main(){
    stack *s = init_stack(6);
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
    destroy_Stack(s);
}

stack * init_stack(size_t size){
    stack * s = (stack *)malloc(sizeof(stack));
    if(!s){
        printf("overflow can't create stack\n");
        return NULL;
    }
    s->size = size;
    s->arr = (int *)malloc(s->size*sizeof(int));
    if (!s->arr){
        printf("overflow can't init the stack array\n");
        return NULL;
    }
    s->top = -1;
    return s;
}

stack * push(stack* s, int data){
    if(s->top>=s->size-1){
        printf("overflow condition\n");
        return s;
    }
    s->top += 1;
    s->arr[s->top] = data;
    return s;
}

int pop(stack* s){
    if(!s) return -1;
    if(s->top-1<0){
        printf("underflow condition\n");
        return -1;
    }
    int top = s->top;
    --s->top;
    return s->arr[top];
}

int peek(stack * s){
    if (!s) return -1;
    if(s->top>=0){
        return s->arr[s->top];
    }
    return -1;
}

void display_stack(stack * s){
    if(!s) return;
    int i = 0;
    while (i<=s->top)
    {
        printf("%d ",  s->arr[i]);
        i++;
    }
    printf("\n");
    
}
void destroy_Stack(stack * s){
    if (!s) return ;
    free(s->arr);
    free(s);
}