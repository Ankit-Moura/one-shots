#include "tree/binary_tree.h"
#include <stdio.h>
int main(){
    struct b_node * root = init_binary_tree(22);
    root = insert_node(root, 20);
    root = insert_node(root, 35);
    root = insert_node(root, 18);
    root = insert_node(root, 25);
    root = insert_node(root, 2);
    root = insert_node(root, 33);
    root = insert_node(root, 59);
    // root = insert_node(root, 40);
    root = insert_node(root, 23);
    // root = insert_node(root, 69);
    root = insert_node(root, 21);
    root = insert_node(root, 19);
    pre_order_traversal(root);
    root = delete_node(root, 18);
    pre_order_traversal(root);
    // pre_order_traversal(root);
    // in_order_traversal(root);
    // post_order_traversal(root);
    // r2 * res = find_min_max(root);
    // printf("min->%d max->%d\n", res->min->data, res->max->data);
    // printf("sum->%d\n", sum(root));
    return 0;
}