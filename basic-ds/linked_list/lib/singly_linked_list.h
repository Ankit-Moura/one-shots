#pragma once


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
struct node * swap(struct node * , int, int);
int item_frequency(struct node *, int);