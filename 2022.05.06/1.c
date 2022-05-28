#include <stdio.h>
#include "queue.h"

void print_queue(queue_t q){
    printf("front = %d rear = %d\n",q.front,q.rear);
    int start = q.front;
    int end = q.rear;
    for(int i = start; i < end; i++){
        printf("%d\n",dequeue(&q));
    }
}


int main(){
    int temp_input;
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

    print_queue(q);
}
