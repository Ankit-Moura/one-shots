#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* link; 
};

struct Node* add_node(struct Node*, int);
void print_linked_list(struct Node*);
void prevent_memory_leaks(struct Node*);

int main(){
    struct Node* head = NULL;

    head = add_node(head, 20);
    head = add_node(head, 55);
    head = add_node(head, 27);
    head = add_node(head, 99);

    print_linked_list(head);
    prevent_memory_leaks(head);
    return 0;
};

struct Node* add_node(struct Node* start, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->link = NULL;
    if(start==NULL){
        start = node;
    }
    else{
        struct Node* ptr = start;
        while (ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = node;
    }
    return start;
};

void print_linked_list(struct Node* start){
    if(start==NULL){
        printf("Linked List is empty");
    }
    else{
        while(start!=NULL){
            printf("%d\n", start->data);
            start = start->link;
        }
    }
}

void prevent_memory_leaks(struct Node* start){
    struct Node* ptr;
    while(start->link!=NULL){
        ptr = start;
        start = start->link;
        free(ptr);
    }
    free(start);
}