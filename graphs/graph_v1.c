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
struct Graph* add_vertex(struct Graph*, int, int*, int); // graph, value, int arr of edges
void destroy_graph(struct Graph*);
struct Node* add_node(struct Node*, int);
void print_linked_list(struct Node*);
void prevent_memory_leaks(struct Node*);

void print_graph(struct Graph* graph){
    for(int i=0; i<graph->size; i++){
        if(graph->vertices[i] == NULL) continue;
        struct Node* ptr = graph->vertices[i];
        printf("vertex %d: ", i+1);
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int main(){
    struct Node* head = NULL;
    int arr1[5] = {23 , 26};
    int arr2[5] = {22, 26};
    int arr3[5] = {25};
    int arr4[5] = {24, 26};
    int arr5[5] = {22, 23, 25};
    

    struct Graph* graph = NULL;
    
    graph = initialize_graph(5);
    graph = add_vertex(graph, 22, arr1, 2);
    graph = add_vertex(graph, 23, arr2, 2);
    graph = add_vertex(graph, 24, arr3, 1);
    graph = add_vertex(graph, 25, arr4, 2);
    graph = add_vertex(graph, 26, arr5, 3);
    print_graph(graph);
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
        // printf("vertices[%d] address: %llu, value: %p\n", 
        //        i, (unsigned long long)(uintptr_t)&graph->vertices[i], 
        //        (void*)graph->vertices[i]);        
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

struct Graph* add_vertex(struct Graph* graph, int value, int*edges, int num_edges){
    // graph->vertices = (struct Node**)malloc(5*sizeof(struct Node*));
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->link = NULL;
    // iterate till end of the vertices array
    int j = 0;
    while(j<graph->size){
        if (graph->vertices[j] == NULL){
            break;
        }
        j++;
    }
    if(graph->vertices[j]!=NULL){
        printf("overflow condition : no more vertex can be added in this graph\n");
        return graph;
    }
    graph->vertices[j] = node;
    int i = 0;
    while(i<num_edges){
        struct Node* edge = (struct Node*)malloc(sizeof(struct Node));
            edge->data = edges[i];
            edge->link = NULL;
            // iterate till end of the list
            struct Node* ptr = graph->vertices[j];
            // ptr can never be zero caz we r setting a node in it above in same function
            while(ptr->link!=NULL){
                ptr = ptr->link;
            }
            ptr->link = edge; // add edge in linked list
            i++;
    }
    return graph;
}

void destroy_graph(struct Graph* graph){
    if(graph == NULL) return;
    for(int i=0; i<graph->size;i++){
        struct Node *ptr = graph->vertices[i];
        while(graph->vertices[i]!=NULL){
            ptr = graph->vertices[i]->link;
            free(graph->vertices[i]);
            graph->vertices[i] = ptr;
        }
    }
    free(graph->vertices);
    free(graph);
}
