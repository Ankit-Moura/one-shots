#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
typedef struct {
    int arr [MAX] [MAX];
    int n_row;
    int n_col;
}matrix;    

matrix*init_matrix(FILE*f);
void print_matrix(matrix * m);
void fill_matrix(matrix* m1, matrix* m2, FILE*f);
matrix * dot_product(matrix*m1, matrix *m2);

int main(){
    FILE *f = fopen("matrix_input.txt", "r");
    if (!f) {
        printf("can't open the file for input\n");
        return -1;
    }
    matrix * m1 = init_matrix(f);
    matrix * m2 = init_matrix(f);
    fill_matrix(m1, m2, f);
    print_matrix(m1);
    printf("------------\n");
    print_matrix(m2);
    printf("---------------\n");
    fclose(f);
    matrix * m3 =  dot_product(m1, m2);
    print_matrix(m3);
    return 0;
}

matrix * init_matrix(FILE * f){
    matrix * m = (matrix *) malloc(sizeof(matrix));
    char line[MAX];
    fgets(line, sizeof(line), f);
    m->n_row = line[0] -  '0';
    m->n_col = line[2] - '0';
    printf("row->%d, col->%d\n", m->n_row, m->n_col);
    memset(m->arr, 0, sizeof(m->arr));
    return m;
}

void print_matrix(matrix * m){
    for(int row = 0; row<m->n_row; row++){
        for(int col = 0; col<m->n_col; col++){
            printf("%d ", m->arr[row][col]);
        }
        printf("\n");
    }
}

void fill_matrix(matrix * m1, matrix * m2, FILE *f){
   
    char line[MAX];
    // for fist matrix   
    for(int r=0; r<m1->n_row; r++){
        
        fgets(line, sizeof(line), f);
        for (int c=0,j = 0;(c<m1->n_col) || (line[j] !='\0'); j++){
            if(isdigit(line[j])){
                m1->arr[r][c] = line[j] - '0';
                c++;
            }
            
        }
       
    }
    fgets(line, sizeof(line), f);
    printf("%s-> un wanted line\n", line);
    // for second matrix 
    for(int r=0; r<m2->n_row; r++){
        char line[MAX];
        fgets(line, sizeof(line), f);
        printf("%s\n", line);        
        for (int c=0,j = 0;(c<m2->n_col) || (line[j] !='\0'); j++){
           
            if(isdigit(line[j])){
                m2->arr[r][c] = line[j] - '0';
                c++;
            }
            
        }
    }
}
matrix * dot_product(matrix *m1, matrix *m2){
    if(m1->n_col != m2->n_row) {
        printf("can't perform matrix multiplication sed life\n");
        return NULL;
    }
    matrix * result = (matrix*) malloc(sizeof(matrix));
    result->n_row = m1->n_row;
    result->n_col = m2->n_col;
    int depth = m1->n_col;
    for (int row = 0; row<result->n_row; row++){
        for (int col=0; col<result->n_col; col++){
            int total = 0;
            for (int i = 0; i<depth; i++){
                int product = m1->arr[row][i] * m2->arr[i][col];
                total += product;
            }   
            result->arr[row][col] = total;
        }
    }
    return result;
}