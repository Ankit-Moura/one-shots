#pragma once
struct b_node{
    struct b_node * left;
    struct b_node * right;
    int data;
};


# include <stdio.h>
#include <stdlib.h>

#include "./binary_tree.h"
#include "../stack/lib/node_stack.h"

typedef struct {
    struct b_node * location;
    struct b_node * parent;
} result;

typedef struct {
    struct b_node * min;
    struct b_node * max;
} r2;

struct b_node * init_binary_tree(int);
struct b_node * insert_node(struct b_node *, int);
result* search(struct b_node * , int);
void pre_order_traversal(struct b_node *);
void in_order_traversal(struct b_node *);
void post_order_traversal(struct b_node *);
struct b_node * delete_node(struct b_node * , int);
r2 * find_min_max(struct b_node *);
int sum(struct b_node * );