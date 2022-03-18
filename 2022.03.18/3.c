#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int count = 0;
    int input;
    int * arr;
    FILE * fp = fopen("data3.txt","r");
    if (fp == NULL){
        printf("error\n");
        return 0;
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&input);
        count++;
    }
    arr = (int *)malloc(sizeof(int) * count);

    rewind(fp);
    for(int i = 0; i< count; i++){
        fscanf(fp,"%d",&arr[i]);
    }

    printf("input array:\n");
    for(int i = 0; i < count; i++){
        (i != count - 1) ? printf("%5d",arr[i]) : printf("%5d\n",arr[i]);
    }
    for(int i = count - 1; i > 0; i--){
        for(int  j = 0; j < i; j++){
            if(arr[j] >arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
    printf("ouput array:\n");
    for(int i = 0; i < count; i++){
        (i != count - 1) ? printf("%5d",arr[i]) : printf("%5d\n",arr[i]);
    }
    fclose(fp);
    return 0;
}
