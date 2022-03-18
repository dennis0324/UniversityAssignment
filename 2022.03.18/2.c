#include <stdio.h>
#include <stdlib.h>


int main(){
    int count = 0;
    int * inputArr;
    int input;
    int small = 0, big = 0;
    FILE * fp = fopen("data2.txt","r");
    if(fp == NULL){
        printf("error\n");
        return 0;
    }

    while(!feof(fp)) {
        fscanf(fp,"%d",&input);
        count++;
    }
    inputArr = (int *)malloc(sizeof(int) * count);
    rewind(fp);
    for(int i = 0; i < count; i++){
        fscanf(fp,"%d",&inputArr[i]);
        if(inputArr[big] < inputArr[i]){
            big = i;
        }
        else if(inputArr[small] < inputArr[i]){
            small = i;
        }
    }

    printf("(");
    for(int i = 0; i < count; i++){
        printf("%d ",inputArr[i]);
    }
    printf(")\n");

    printf("최댓값은 %d\n최솟값은 %d",inputArr[big],inputArr[small]);
    fclose(fp);

    return 0;
}
