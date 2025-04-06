#include "./lib/doubly_linked_list.h"

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


