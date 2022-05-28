#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct 
{
    int id;
    char name[20];
}element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear; 
}queue_t;

void init(queue_t * q){
    q ->front = q ->rear = 0;
}

int is_full(queue_t * q){
    return (q-> rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(queue_t * q){
    return q->front == q->rear;
}

void enqueue(queue_t * q,element value){
    if(is_full(q)) return;
    q->rear = (++q->rear) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

element dequeue(queue_t * q){
    if(is_empty(q)) return ;
    q->front = (++q->front) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(queue_t * q){
    if(is_empty(q)) return ;
    return q->data[q->front];
}

int get_count(queue_t * q){
    return (q->rear - q->front - 1);
}

void print_queue(queue_t q){
    
    int start = q.front;
    int end = q.rear;
    element e;
    for(int i = start; i < end; i++){
        e = dequeue(&q);
        printf("front = %d rear = %d  ",q.front,q.rear);
        printf("%d | %s\n",e.id, e.name);
    }
}

int main(){
    int temp1;
    char temp2[20];
    element temp;
    queue_t q;
    init(&q);
    FILE * fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file not found");
        return 0;
    }

    while(!feof(fp)){
        
        fscanf(fp,"%d %s",&temp1,temp2);
        temp.id = temp1;
        strcpy(temp.name,temp2);
        enqueue(&q,temp);
    }

    print_queue(q);
    printf("큐의 길이: %d ",get_count(&q));
    fclose(fp);
    return 0;
}