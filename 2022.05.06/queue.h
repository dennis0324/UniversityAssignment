#include <stdio.h>


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

int length(queue_t * q){
    return (q->rear - q->front - 1);
}

int get_count(queue_t * q){
    return (q->rear - q->front - 1);
}
