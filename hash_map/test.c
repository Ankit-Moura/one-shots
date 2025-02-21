#include  <stdio.h>

int main(){
    char str1[5] = "ankit";
    char str2[5] = "ankit";
    int s1 = sizeof(str1)/sizeof(str1[0]);
    int s2 = sizeof(str2)/sizeof(str2[0]);
    if (s1<s2){
        int i = 0;
        while(str1[i] != '\0'){
            if (str1[i] == str2[i]){
                i++;
                continue;
            }
            return -1;
        }
        printf("same");
        return 1;
    }
    else{
        int i = 0;
        while(str2[i] != '\0'){
            if (str1[i] == str2[i]){
                i++;
                continue;
            }
            return -1;
        }
        printf("same");
        return 1;
    }
    return 0;
}
