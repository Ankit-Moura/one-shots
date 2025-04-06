#pragma once

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