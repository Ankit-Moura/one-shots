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

int hash(person * p, hash_map * h){
    int sum = 0;
    unsigned int i =  0;
    while(p->name[i] != '\0'){
        sum += p->name[i];
        i++;
    }
    sum = sum%SIZE;
    if (h->arr[sum]!=NULL){
        printf("collision....between %s and %s\n", h->arr[sum]->name, p->name);
        int j = sum;
        j = (j+1)%SIZE;
        sum = 0;
        while (h->arr[j]!=NULL && sum<SIZE){
            j = (j+1)%SIZE;
            sum++;
        }
        if (h->arr[j]==NULL){
            h->arr[j] = p;
            return 0;
        }
        else{
            printf("map is full sed life...%s\n", p->name);
            return -1;
        }
    }
    h->arr[sum%SIZE] = p;
    return 0;
}

void printHashMap(hash_map *h){
    for (int i = 0; i<SIZE; i++){
        if (h->arr[i] == NULL){
            printf("arr[%d]--->NULL\n", i);
            continue;
        }
        printf("arr[%d]--->%s\n", i, h->arr[i]->name);
    }
    printf("---------------------------------\n");
}

int main(){
    hash_map *h = init_hash_map();
    printf("hash map initalized\n");
    person p1 = {.age = 21, .name = "ankit"};
    person p2 = {.age = 21, .name = "joe"};
    person p3 = {.age = 21, .name = "moe"};
    person p4 = {.age = 21, .name = "roe"};
    person p5 = {.age = 21, .name = "feet pics?"};
    person p6 = {.age = 21, .name = "alice"};
    person p7 = {.age = 21, .name = "bob"};
    person p8 = {.age = 21, .name = "charlie"};
    person p9 = {.age = 21, .name = "dave"};
    person p10 = {.age = 21, .name = "eve"};
    person p11 = {.age = 21, .name = "overflow"};

    // Inserting into hash map
    hash(&p1, h);
    hash(&p2, h);
    hash(&p3, h);
    hash(&p4, h);
    hash(&p5, h);
    hash(&p6, h);
    hash(&p7, h);
    hash(&p8, h);
    hash(&p9, h);
    hash(&p10, h);
    hash(&p11, h); 
    printHashMap(h);
    return 0;
}
