#include<stdio.h>
#include<stdlib.h>
#include "./singly_linked_list.h"

void print_ll(struct node *start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->link;
    }
    printf("\n");
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

int item_frequency(struct node * head, int item){
    if(!head)return -1;
    struct node * temp = head;
    int count = 0;
    while (temp)
    {
        if(temp->data == item){
            count += 1;
        }
        temp = temp->link;
    }
    return count;
}

struct node * swap(struct node * head, int n, int m){
    if(!head){
        return NULL;
    }
    if(n == m){
        return head;
    }
    struct node * n1, *m1, *temp, *p1, *p2;
    temp = head;
    n1 = head;
    m1 = head;
    p1 = NULL;
    p2 = NULL;
    for(int i = 1; i<n; i++){
        p1 = temp;
        temp = temp->link;
        if(!temp){
            printf("invalid swapping position %d\n", n);
            return head;
        }
    }
    n1 = temp;
    temp = head;
    for(int y = 1; y<m; y++){
        p2=temp;
        temp = temp->link;
        if(!temp){
            printf("invalid swapping position %d\n", m);
            return head;
        }
    }
    m1 = temp;
    if(!p1 || !p2){
        // swapping from the front
        if(!p1){
            head = m1;
            p2->link = m1->link;
            m1->link = n1->link;
            n1->link = p2->link;
            p2->link = n1;
            return head;            

        }else{
            head = n1;
            p1->link = n1->link;
            n1->link = m1->link;
            m1->link = p1->link;
            p1->link = m1;
            return head; 
        }

    }

    p1->link = n1->link;
    p2->link = m1->link;
    m1->link = p1->link;
    p1->link = m1;
    n1->link = p2->link;
    p2->link = n1;
    return head;


}