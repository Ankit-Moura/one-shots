#include<stdio.h>
#include<stdlib.h>

void counting_sort(int arr[], int len){
    int max = 0;
    // find the greatest ele in array
   
    for (int i = 0; i<len; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int *freq = (int *) calloc(max + 1, sizeof(int));

    for (int i = 0; i<len; i++){
        freq[arr[i]] += 1;
    }
    int csum = 0;
    for (int i = 0; i<max+1; i++){
        csum += freq[i];
        printf("%d->%d\n", i, freq[i]);
    }
    
    int * op = (int *)malloc(sizeof(int)*csum);
    int ln = csum;
    int i = 0;
    int j = 0;
    while (csum)
    {
        if (freq[j])
        {
            op[i] = j;
            freq[j] -= 1;
            i++;
            csum--;
            continue;
        }
        j++;
        if(j>max){
            break;
        }        
    }
    for (int i = 0; i < ln; i++)
    {
        printf("%d ", op[i]);
    }
    
}

int main(){
    int arr[] =  {2, 5, 7, 3, 1, 6, 7, 8, 1};
    int len = sizeof(arr)/sizeof(int);
    counting_sort(arr, len);
    
    return 0;
}
