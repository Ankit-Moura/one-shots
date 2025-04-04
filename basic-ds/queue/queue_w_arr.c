#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int * arr;
    int size;
} queue;

queue * init_queue(size_t);
queue * enqueue(queue *, int);
queue * dequeue(queue *);
int peak(queue *, int);
void display_queue(queue *);

int main(){
    queue * q = init_queue(10);
    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);
    q = enqueue(q, 40);
    printf("%d, %d\n", q->front, q->rear);
    display_queue(q);
    q = dequeue(q);
    q = dequeue(q);
    q = dequeue(q);
    display_queue(q);
    q = enqueue(q, 22);
    q = enqueue(q, 23);
    q = enqueue(q, 24);
    printf("%d", peak(q, 0));
    q = dequeue(q);
    display_queue(q);
    return 0;
}

void display_queue(queue * q){
    if(!q) return ;
    int i = q->front;
    if(i<0)return;
    if(q->front==q->rear){
        printf("%d\n", q->arr[i]);
        return;
    }
    while (i!=q->rear)
    {
        printf("%d ", q->arr[i]);
        i  = (i +1 )%q->size;
    }
    printf("%d\n", q->arr[i]);
    
}

queue * init_queue(size_t size){
    queue * q = (queue *)malloc(sizeof(queue));
    if(!q){
        printf("overflow condition\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
    if (!q->arr){
        printf("overflow condition couldn't init array\n");
        return NULL;
    }
    return q;
}

queue * enqueue(queue * q, int data){
    if(!q){
        printf("NULL queue\n");
        return NULL;
    }
    if(q->rear==-1){
        // handle first ele case
        q->rear++; 
        q->front ++;
        q->arr[q->rear] = data;
        return q;
    }
    if(q->rear+1 % q->size  == q->front){
        // queue is full
        printf("queue is full \n");
        return q;    printf("%d, %d\n", q->front, q->rear);
    }
    q->rear = (q->rear + 1 )%q->size;
    q->arr[q->rear] = data;
    return q;
}

queue * dequeue(queue * q){
    if (!q){
        printf("queue doesn't exist\n");
        return NULL;
    }
    if (q->front<0){
        printf("underflow condition\n");
        return q;        
    }
    // if only element in q is dequeued 
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return q;
    }
    q->front = (q->front + 1)%q->size;
    return q;
}
int peak(queue *q, int isRear){
    if(!q) return -1;
    if(isRear) {
        if(q->rear>=0){
        return q->arr[q->rear];
        }
    }
    if(q->front>=0){
    return q->arr[q->front];}
    printf("queue is empty\n");
    return -1;
}