#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

bool compareString(char * str1, char * str2){
    int s1 = sizeof(str1)/sizeof(str1[0]);
    int s2 = sizeof(str2)/sizeof(str2[0]);
    if (s1<s2){
        int i = 0;
        while(str1[i] != '\0'){
            if (str1[i] == str2[i]){
                i++;
                continue;
            }
            return false;
        }
        return true;
    }
    else{
        int i = 0;
        while(str2[i] != '\0'){
            if (str1[i] == str2[i]){
                i++;
                continue;
            }
            return false;
        }
        return true;
    }
    return false;
}

int hash(char * key, hash_map * h){
    int sum = 0;
    unsigned int i =  0;
    while(key[i] != '\0'){
        sum += key[i];
        i++;
    }
    sum = sum%SIZE;
    if (h->arr[sum]!=NULL){
        if (compareString(h->arr[sum]->name, key)){
            return sum;
        }
        printf("collision....between %s and %s\n", h->arr[sum]->name, key);
        int j = sum;
        j = (j+1)%SIZE;
        sum = 0;
        while (h->arr[j]!=NULL && sum<SIZE){
            j = (j+1)%SIZE;
            sum++;
        }
        if (h->arr[j]==NULL){
            return j;
        }
        else{
            printf("map is full sed life...%s\n", key);
            return -1;
        }
    }
    return sum;
}

int getHash(char * key, hash_map * h){
    int sum = 0;
    unsigned int i =  0;
    while(key[i] != '\0'){
        sum += key[i];
        i++;
    }
    sum = sum%SIZE;
    if (h->arr[sum]!=NULL){
        if (compareString(h->arr[sum]->name, key)){
            return sum;
        }
        printf("collision....between %s and %s\n", h->arr[sum]->name, key);
        int j = sum;
        j = (j+1)%SIZE;
        sum = 0;
        while (h->arr[j]!=NULL && sum<SIZE){
            if (compareString(h->arr[j]->name, key)) return j;
            j = (j+1)%SIZE;
            sum++;
        }
        printf("can't find %s in map sed life\n", key);
        return -1;
    }
    return sum;
}


void insert_ele( person *p, hash_map *h){
    int index = hash(p->name, h);
    if (index == -1) return;
    h->arr[index] = p;
    return;
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

void find_ele( char * name, hash_map * h){
    int i = getHash(name, h);
    if (i == -1){
        printf("%s doesn't exit in map\n", name);
        return ;
    }
    printf("%s is at arr[%d]\n", name, i);
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
    insert_ele(&p2, h);
    insert_ele(&p1, h);
    insert_ele(&p3, h);
    insert_ele(&p4, h);
    insert_ele(&p5, h);
    insert_ele(&p6, h);
    insert_ele(&p7, h);
    insert_ele(&p8, h);
    insert_ele(&p9, h);
    insert_ele(&p10, h);
    insert_ele(&p11, h); 
    printHashMap(h);
    find_ele("ankit", h);
    find_ele("roe", h);
    find_ele("xxx", h);

    return 0;
}
