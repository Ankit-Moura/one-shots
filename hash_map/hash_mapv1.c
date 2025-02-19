#include<stdio.h>
#include<stdlib.h>
#define MAXNAME 250
#define SIZE 10


typedef struct {
    int age;
    char name[MAXNAME];
}person;

typedef struct{
    person* arr[SIZE];
}hash_map;

hash_map * init_hash_map(){
    hash_map *h = (hash_map *)malloc(sizeof(hash_map));
    if (h == NULL) return h;
    for (int i = 0; i<SIZE; i++){
        h->arr[i] = NULL;
    }
    return h;
}

int main(){
    person p = {.age=21, .name="ankit"};
    hash_map *h = init_hash_map();
    printf("hash map initalized\n");
    return 0;
}
