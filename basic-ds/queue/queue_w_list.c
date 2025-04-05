#include <stdio.h>
#include <stdlib.h>
#include "./../linked_list/lib/singly_linked_list.h"


typedef struct {
    struct node * front;
    struct node * rear;
} queue;

queue * init_queue();
queue * enqueue(queue *, int);
queue * dequeue(queue *);
int peak(queue *, int);
void display_queue(queue *);

int main(){
    queue * q = init_queue();
    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);
    q = enqueue(q, 40);
    display_queue(q);
    printf("f->%d, r->%d\n", q->front->data, q->rear->data);
    q = dequeue(q);
    q = dequeue(q);
    q = dequeue(q);
    display_queue(q);
    q = enqueue(q, 22);
    q = enqueue(q, 23);
    q = enqueue(q, 24);
    printf("%d\n", peak(q, 0));
    q = dequeue(q);
    display_queue(q);
    return 0;
}
 

queue * init_queue(){
    queue * q = (queue *)malloc(sizeof(queue));
    if (!q){
        printf("overflow condition\n");
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

queue * enqueue(queue * q, int data){
    if(!q) return q;
    if(q->rear == NULL){
        // empty queue case
        q->rear = insert_node(q->rear, data, 0);
        if(!q->rear){
            return NULL;
        }
        q->front = q->rear;
        return q;
    }
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    if(!n){
        printf("overflow\n");
        return q;
    }
    n->data = data;
    n->link = NULL;
    q->rear->link = n;
    q->rear = n;
    return q;
}

queue * dequeue(queue * q){
    if(!q) return NULL;
    if(!q->front){
        printf("underflow condition in queue \n");
        return q;
    }
    // case 1 when q contains single element 
    if(q->front == q->rear){
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        return q;
    }
    struct node * temp = q->front;
    q->front = q->front->link;
    free(temp);
    return q;
}

int peak(queue * q, int isRear){
    if(!q) return -1;
    if(isRear && q->rear){
        return q->rear->data;
    }else if(q->front && !isRear){
        return q->front->data;
    }else{
        return -1;
    }
}

void display_queue(queue * q){
    if(!q || !q->front) return;
    print_ll(q->front);
}