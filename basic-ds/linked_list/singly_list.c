#include<stdio.h>
#include<stdlib.h>
#include "./lib/singly_linked_list.h"
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
