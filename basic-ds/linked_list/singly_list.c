#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_ll(struct node *);
struct node *append_node(struct node *, int);
struct node * insert_node(struct node * , int, unsigned int);
struct node * delete_node(struct node *, int);
int search_item(struct node *, int);
void delete_linked_list(struct node *);
void describe_dataStructure();
int main() {
    struct node *list = NULL;
    list = append_node(list, 5);
    list = append_node(list, 0);
    list = append_node(list, 228);
    list = append_node(list, 67);
    list = append_node(list, 34);
    print_ll(list);
    printf("item found %d\n", search_item(list, 67));
    printf("item found %d\n", search_item(list, 7));
    list = insert_node(list , 44, 2);
    list = delete_node(list, 0);
    print_ll(list);
    delete_linked_list(list);
    describe_dataStructure();
    return 0;
}

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

void describe_dataStructure() {
    printf("====================================\n");
    printf("       Singly Linked List (SLL)     \n");
    printf("====================================\n");
    printf("A singly linked list is a linear data structure where each node contains:\n");
    printf("1. Data: The actual value stored in the node.\n");
    printf("2. Link (Pointer): A pointer to the next node in the list.\n\n");

    printf("Operations & Their Time Complexities:\n");
    printf("1. Insertion at Beginning: O(1)\n");
    printf("2. Insertion at End: O(n)\n");
    printf("3. Insertion at Middle: O(n)\n");
    printf("4. Deletion at Beginning: O(1)\n");
    printf("5. Deletion at End: O(n)\n");
    printf("6. Deletion in Middle: O(n)\n");
    printf("7. Search for an Element: O(n)\n");
    printf("8. Printing the List: O(n)\n\n");

    printf("Space Complexity: O(n) (Each node takes space for data and a pointer)\n");
    printf("====================================\n\n");
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