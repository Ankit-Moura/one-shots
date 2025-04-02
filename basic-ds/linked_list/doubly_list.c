#include<stdio.h>
#include<stdlib.h>

struct d_node {
    struct d_node * left;
    int data;
    struct d_node * right;
};

struct d_node * init_doubly_list(int);
void display_list(struct d_node *);
struct d_node * append_node(struct d_node*, int);
struct d_node * insert_node(struct d_node *, int, int);
struct d_node * delete_node(struct d_node *, int);
int search_item(struct d_node *, int);
void delete_linked_list(struct d_node *);
void describe_dataStructure();
int main(){
    struct d_node * list = init_doubly_list(22);
    display_list(list);
    list = append_node(list, 10);
    list = append_node(list, 11);
    list = append_node(list, 12);
    list = append_node(list, 13);
    list = append_node(list, 14);
    display_list(list);
    list = insert_node(list, 29, 0);
    printf("%d\n", search_item(list, 33)); 
    list = insert_node(list, 33, 1);
    printf("%d\n", search_item(list, 33)); 
    list = insert_node(list, 88, 4);
    display_list(list);
    list = delete_node(list, 29);
    list = delete_node(list, 14);
    list = delete_node(list, 10);
    display_list(list);
    delete_linked_list(list);
    return 0;
};


int search_item(struct d_node * head, int item){
    if(!head){
        return -1;
    }
    struct d_node * temp = head;
    while(temp){
        if (temp->data == item){
            return 1;
        }
        temp = temp->right;
    }
    return -1;
}

void display_list(struct d_node * head){
    if (!head) return;
    struct d_node * temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

struct d_node * init_doubly_list(int data){
    struct d_node * list = (struct d_node *)malloc(sizeof(struct d_node));
    if (list){
        list->left = NULL;
        list->data = data;
        list->right = NULL; 
        return list;}
    printf("overflow condition no space in memory");
    return list;
}

struct d_node * append_node(struct d_node * head, int data){
    if(head){
        if(!head->data){
            head->data = data;
            return head;
        }
        struct d_node * temp = head;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        struct d_node * node = init_doubly_list(data);
        if (!node) return head;
        node->left = temp;
        temp->right = node;
        return head;
    }
}

struct d_node * insert_node(struct d_node * head, int data, int index){
    if(!head){
        if (index!=0){
            printf("invalid insertion index\n");
        }
        return init_doubly_list(data);
    }
    struct d_node * temp = head;
    // handle insertion at begining 
    if (index == 0){
        temp = init_doubly_list(data);
        head->left = temp;
        temp->right = head;
        return temp;
    }
    while(index> 0){
        if (!temp->right){
            if(index == 1){
            // insertion at last position
            struct d_node* n = init_doubly_list(data);
            if(!n) return head;
            temp->right = n;
            n->left = temp;
            return head;
            }
            printf("invalid insertion index\n");
            return head;
        }
        temp = temp->right;
        index--;
    }
    struct d_node * node = init_doubly_list(data);
    if (!node)  return head;
    node->right = temp;
    node->left = temp->left->right;
    temp->left->right = node;
    temp->left = node;
    return head;

}

struct d_node* delete_node(struct d_node * head,int data){
    if(!head){
        printf("underflow condition\n");
        return head;
    }
    struct d_node * temp = head;
    if (temp->data == data){
        // deletion from begining
        head = head->right;
        free(temp);
        return head;
    }

    while(temp){
        if (temp->data == data){
            break;
        }
        temp = temp->right;
    }
    if (!temp) return head;
    if (temp->right==NULL){
        // deletion at the end
        temp->left->right = NULL;
        free(temp);
        return head;
    } 
    // deletion in between
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
    return head;
}

void delete_linked_list(struct d_node * head){
    if (!head)return;
    struct d_node * prev = head;
    while(head){
        prev = head;
        head = head->right;
        free(prev);
    }

}