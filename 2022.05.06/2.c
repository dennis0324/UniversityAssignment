#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int compare(const int *a, const int *b)    // 오름차순 비교 함수 구현
{

    if (*a < *b)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (*a > *b)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(){
    int temp_input;
    int n =1;
    int end;
    queue_t q;
    init(&q);
    FILE * fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file not found");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp,"%d",&temp_input);
        enqueue(&q,temp_input);
    }

    qsort((q.data + q.front + 1),length(&q), sizeof(int),compare);
    end = length(&q);
    for(int i =0; i < end; i++){
        printf("%d ->",dequeue(&q));
    }
}