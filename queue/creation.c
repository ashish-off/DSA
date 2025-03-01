#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

struct Queue {
  int front;
  int rear;
  int items[MAX];
};
//inatalizing 
void initializeQueue(struct Queue *q) {
  q->front = -1;
  q->rear = -1;
}

//  dispaying queue
void display(struct Queue *q) {
  int i;
  if (q -> front == -1)
  {
    printf("Queue is empty\n");
  }else{
    printf("Front index -> %d \n ", q -> front);
    printf(" Items -> ");
    for (i = q -> front; i <= q -> rear; i++)
    {
      printf("%d ", q -> items[i]);
    }
    printf("\nRear index -> %d\n", q -> rear);
  }
}

// enqueue
void enqueue(struct Queue *q, int value) {
  if (q -> rear == MAX-1)
  {
    printf("Queue is full\n");
  }else{
    if (q -> front == -1) // if the queue is initially empty
    {
      q -> front = 0;
    }
    q -> rear++;
    q -> items[q -> rear] = value;
    printf("Inserted -> %d\n", value);
  }
  
}

int main () {
  struct Queue q;

  initializeQueue(&q);  
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 8);
  enqueue(&q, 6);
  enqueue(&q, 9);
  enqueue(&q, 9);
  display(&q);
  return 0;
}