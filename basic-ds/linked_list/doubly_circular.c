#include "./lib/doubly_linked_list.h"

struct d_node * init_cdl(int data);
struct d_node * append_node_cdl(struct d_node *, int);
struct d_node * delete_node_cdl(struct d_node *, int);
void display_circular_doubly_list(struct d_node *);

int main(){
    struct d_node * list = init_cdl(22);
    display_circular_doubly_list(list);
    list = append_node_cdl(list, 23);
    list = append_node_cdl(list, 24);
    list = append_node_cdl(list, 25);
    list = append_node_cdl(list, 26);
    list = append_node_cdl(list, 27);
    display_circular_doubly_list(list);
    list = delete_node_cdl(list, 22);
    list = delete_node_cdl(list, 24);
    list = delete_node_cdl(list, 27);
    display_circular_doubly_list(list); 
    return 0;
}



struct d_node * init_cdl(int data){
    struct d_node * n = init_doubly_list(data);
    if(!n) return NULL;
    n->left = n;
    n->right = n;
    return n;
}

struct d_node * append_node_cdl(struct d_node * head, int data){
    if(!head){
        printf("initialise your circular linked list first\n");
        return NULL;
    }
    struct d_node *newNode;
    newNode = init_doubly_list(data);
    if(!newNode){
        return head;
    }
    
    newNode->right = head;
    newNode->left = head->left;
    head->left->right = newNode;
    head->left = newNode;
    return head;
}

struct d_node * delete_node_cdl(struct d_node* head, int item){
    if (!head){
        return NULL;
    }
    struct d_node * ptr;
    // deletion from first
    if (head->data == item ){
        if(head->right == head){
            // if head is only node
            free(head);
            return NULL;
        }else{
            ptr = head->left;
            head->right->left = ptr;
            ptr->right = head->right;
            free(head);
            return ptr->right;
        }
    }
    // deletion in between
    ptr = head;
    while(ptr->right!=head){
        if(ptr->data==item){
           ptr->left->right = ptr->right;
           ptr->right->left = ptr->left;
           free(ptr);
        }
        ptr = ptr->right;
       
    }
    if(ptr->data == item){
        //deletion from end
        ptr->left->right = head;
        head->left = ptr->left;
        free(ptr);
    }
    return head;
}

void display_circular_doubly_list(struct d_node * head){
    if(!head){
        return;
    }
    struct d_node * temp = head;
    while (temp->right!=head)
    {
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("%d\n", temp->data);
}