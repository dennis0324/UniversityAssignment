#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100
typedef struct {
   int nNum;
   char name[100];
}QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;

void initialize() {
   front = rear = 0;
}

int isEmpty() {
   return (front == rear);
}

int isFull() {
   return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item) {
   if (isFull()) {
      printf("queue is full.");
      exit(0);
   }
   rear = (rear + 1) % MAX_QUEUE_SIZE;
   queue[rear] = item;
}

QueueObject deleteq() {
   if (isEmpty()) {
      printf("queue is empty.");
      exit(0);
   }

   front = (front + 1) % MAX_QUEUE_SIZE;
   return queue[front];
}
int getCount() {
   return rear - front;
}
void main() {
   int get;
   int data;
   initialize();
   char name[100];
   FILE *fp;
   fp = fopen("data2.txt", "r");
   if (fp == NULL) {
      fprintf(stderr, "FILE OPEN ERROR");
      exit(1);
   }
   int nCount = 1;
   while (!feof(fp)) {
      fscanf(fp, "%d %s",&data,name);

      queue[nCount].nNum = data;

      addq(queue[nCount]);
      nCount++;
   }
   printf("front : %d rear : %d\n", front, rear);
   printf("학번\t\t||이름\n");
   for (int j = 0; j < nCount-1; j++) {
      QueueObject temp;
      temp = deleteq();
      printf("%d\t%s", temp.nNum, temp.name);
      get = getCount();
      printf("요소의 개수 : %d\n", get);
   }

   printf("front : %d rear : %d\n", front, rear);
   fclose(fp);
}