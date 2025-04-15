#include "./node_stack.h" 

stack * init_stack(size_t size){
    stack * s = (stack *)malloc(sizeof(stack));
    if(!s){
        printf("overflow can't create stack\n");
        return NULL;
    }
    s->size = size;
    s->arr = (struct b_node **)malloc(s->size*sizeof(struct b_node));
    if (!s->arr){
        printf("overflow can't init the stack array\n");
        return NULL;
    }
    s->top = -1;
    return s;
}

stack * push(stack* s, struct b_node *data){
    if(s->top>=s->size-1){
        printf("overflow condition\n");
        return s;
    }
    s->top += 1;
    s->arr[s->top] = data;
    return s;
}

struct b_node* pop(stack* s){
    if(!s) return NULL;
    if(s->top-1<-1){
        printf("underflow condition\n");
        return NULL;
    }
    int top = s->top;
    --s->top;
    return s->arr[top];
}

int peek(stack * s){
    if (!s) return -1;
    if(s->top>=0){
        return s->arr[s->top]->data;
    }
    return -1;
}

void display_stack(stack * s){
    if(!s) return;
    int i = 0;
    while (i<=s->top)
    {
        printf("%d ",  s->arr[i]->data);
        i++;
    }
    printf("\n");
    
}
void destroy_Stack(stack * s){
    if (!s) return ;
    free(s->arr);
    free(s);
}