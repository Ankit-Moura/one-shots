#include<stdio.h>
#include<stdlib.h>
#include "./singly_linked_list.h"

void print_ll(struct node *start) {
    while (start != NULL) {
        printf("%d\n", start->data);
        start = start->link;
    }
}

struct node *append_node(struct node *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("overFLow\n");
        return list;
    }
    new_node->data = data;
    new_node->link = NULL;

    if (list == NULL) {
        return new_node;
    }

    struct node *temp = list;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;
    return list;
}
struct node * insert_node(struct node * list, int data,unsigned int index){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("overflow condition\n");
        return list;
    }
    new_node->data = data;
    new_node->link = NULL;
    if (index == 0){
        new_node->link = list;
        return new_node;
    }
    struct node* temp = list;
    if (temp == NULL){
        printf("linked list doesn't exist\n");
        return list;
    }
    index--;
    while(index){
        if (!temp->link){
            printf("invalid index\n");
            return list;
        }
        temp = temp->link;
        index--;
    }

    new_node->link = temp->link;
    temp->link = new_node;
    return list;
}
struct node * delete_node(struct node * list, int item){
  
    struct node * temp = list;
    if(!temp)return list;
    struct node * prev =NULL;
      // check if 1st node is being popped
    if(list->data == item){
        list = list->link;
        free(temp);
        return list;
    }
    
    while(temp->link){
        if (temp->data == item){
            break;
        }
        prev = temp;
        temp = temp->link;
    }
    if (temp->data!=item){
        printf("item doesn't exist\n");
        return list;
    }
    prev->link = temp->link;
    free(temp);
    return list;
}

int search_item(struct node * head, int item){
    struct node * temp = head;
    if (!temp) return -1;
    while(temp){
        if (temp->data == item){
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}


void delete_linked_list(struct node * head){
    if(!head) return;
    struct node* next = head->link;
    while(next){
        free(head);
        head = next;
        if (next){
            next = next->link;
        }
    }
    free(head);
}
