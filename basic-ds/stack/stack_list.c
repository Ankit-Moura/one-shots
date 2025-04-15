#include "lib/stack_ll.h"
#include <stdio.h>
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