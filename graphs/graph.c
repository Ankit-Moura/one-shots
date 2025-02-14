#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct Node{
    int data;
    struct Node* link; 
};

struct Graph{
    int size;
    struct Node ** vertices;
};
struct Graph* initialize_graph(int num_vertices);
struct Graph* add_vertex(struct Graph*, int, int*); // graph, value, int arr of edges
void destroy_graph(struct Graph*);
struct Node* add_node(struct Node*, int);
void print_linked_list(struct Node*);
void prevent_memory_leaks(struct Node*);

int main(){
    struct Node* head = NULL;
    int arr[5] = {1, 2, 3, 4, 5};
    head = add_node(head, 20);
    head = add_node(head, 55);
    head = add_node(head, 27);
    head = add_node(head, 99);

    struct Graph* graph = NULL;
    
    graph = initialize_graph(5);

    // print_linked_list(head);
    destroy_graph(graph);
    prevent_memory_leaks(head);
    return 0;
};

struct Graph* initialize_graph(int num_vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->size = num_vertices;
    // assign memory to vertices arr
    graph->vertices = (struct Node **)malloc(graph->size*sizeof(struct Node*));
    for(int i=0; i<graph->size; i++){
        graph->vertices[i] = NULL;
        // printf("vertices[%d] address: %p, value: %p\n", 
        //    i, (void*)&graph->vertices[i], (void*)graph->vertices[i]);
        printf("vertices[%d] address: %llu, value: %p\n", 
               i, (unsigned long long)(uintptr_t)&graph->vertices[i], 
               (void*)graph->vertices[i]);        
    }
    return graph;
}

struct Node* add_node(struct Node* start, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->link = NULL;
    if(start==NULL){
        start = node;
    }
    else{
        struct Node* ptr = start;
        while (ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = node;
    }
    return start;
};

void print_linked_list(struct Node* start){
    if(start==NULL){
        printf("Linked List is empty");
    }
    else{
        while(start!=NULL){
            printf("%d\n", start->data);
            start = start->link;
        }
    }
}

void prevent_memory_leaks(struct Node* start){
    struct Node* ptr = NULL;
    while(start!=NULL){
        ptr = start;
        start = start->link;
        free(ptr);
    }
}

struct Graph* add_vertex(struct Graph* graph, int value, int*edges){
    // graph->vertices = (struct Node**)malloc(5*sizeof(struct Node*));
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
    node->data = value;
    node->link = NULL;
    graph->vertices[0] = node;
    if (edges==NULL) return graph;
    int i = graph->size;
    while(i){
        if (edges[i]==NULL){
            return;
        }
        else{
            // create new node attach it i hate my life
        }
    }
}

void destroy_graph(struct Graph* graph){
    if(graph == NULL) return;
    free(graph->vertices);
    free(graph);
}