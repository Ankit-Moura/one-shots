#include <stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node * link;
};

struct node * init_head_node(int);
struct node * append_node(struct node *,int);
void display_list(struct node *);
struct node * insert_node(struct node *, int, int);
struct node * delete_node(struct node *, int);
int search_item(struct node *, int);
void destroy_list(struct node *);
void describe_dataStructure();

int main(){
    struct node * list = init_head_node(19);
    list = append_node(list, 13);
    list = append_node(list, 3);
    list = append_node(list, 12);
    list = append_node(list, 15);
    list = append_node(list, 10);
    display_list(list);
    list = delete_node(list,10);
    display_list(list);
    return 0;
}

struct node * init_head_node(int data){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    if (!head){
        printf("overflow condition : system out of memory\n");
        return NULL;
    }
    head->data = data;
    head->link = head;
    return head;
}

struct node * append_node(struct node * head, int data){
    if(!head){
        printf("initialise the head node first!!!\n");
        return NULL;
    }
    struct node * temp = head;
    while(temp->link!= head){
        temp = temp->link;
    }
    struct node * node = (struct node *)malloc(sizeof(struct node ));
    if (!node){
        printf("overflow condition\n");
        return head;
    }
    node->data = data;
    node->link = head;
    temp->link = node;
    return head;
}

void display_list(struct node * head){
    if (!head){
        printf("list is empty\n");
        return;
    }
    struct node * temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }while(temp!=head);
    printf("\n");
}

struct node * insert_node(struct node * head, int data, int index){
    if(!head){
        if (index==0){
            return init_head_node(data);
        }
        printf("invalid index the head node is NULL\n");
    }
    struct node * temp = head;
    struct node * n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    // insertion at the begining
    if (index == 0){
        n->link = head;
        while (temp->link!= head)
        {
            temp=temp->link;
        }
        temp->link = n;
        return n;
    }
    for (int i=0; i<index-1; i++){
        temp = temp->link;
        if (temp==head){
            printf("invalid insertion index %d\n", index);
            return head;
        }
    }
    n->link = temp->link;
    temp->link = n;
    return head;
}

struct node * delete_node(struct node * head, int item){
    if(!head){
        printf("underflow list is empty\n");
        return NULL;
    }
    struct node * temp, *node; 
    temp = head;
    // deletion of only node
    if (head->data == item && head->link == head) {
        free(head);
        return NULL;
    }
    do{
        if(temp->link->data==item){
            node = temp->link;
            temp->link = node->link;
            if (node == head){
                head = node->link;
            }
            free(node);
            return head;
        }
        temp = temp->link;
    }while(temp!=head);
    return head;
}

int search_item(struct node * head, int item){
    if(!head)return -1;
    struct node * temp = head;
    do{
        if (temp->data == item){
            return 1;
        }
        temp = temp->link;    
    }while(temp!=head);
    return -1;
}

void destroy_list(struct node* head){
    if(!head)return;
    struct node * temp, *prev;
    temp = head->link;
    while (temp!=head)
    {
        prev = temp;
        temp = temp->link;
        free(prev);
    }
    free(head);
}

void describe_dataStructure() {
    printf("Circular Linked List:\n");
    printf("A Circular Linked List is a variation of a linked list in which the last node points back to the head, forming a circular structure.\n");
    printf("This structure allows for constant-time insertion and deletion at both ends while avoiding NULL pointers.\n\n");

    // Time and Space Complexity Analysis
    printf("Operations and their complexities:\n");
    printf("Insertion at beginning: O(n)\n");
    printf("Insertion at end: O(n)\n");
    printf("Insertion at a specific position: O(n)\n");
    printf("Deletion from beginning: O(n)\n");
    printf("Deletion from end:O(n)\n");
    printf("Deletion of a specific node: O(n)\n");
    printf("Searching: O(n)\n");
    printf("Traversal: O(n)\n");
    printf("Space Complexity: O(n) (for storing n nodes)\n");
}