#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct Queue {
    int front;
    int rear;
    int items[MAX];
};

// Initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
bool isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
bool isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Display the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("\nFront index -> %d\n", q->front);
        printf("Items -> ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\nRear index -> %d\n", q->rear);
    }
}

// Enqueue an element
void enqueue(struct Queue *q, int value){
  if (isFull(q))
  {
    printf("Queue is full, cannot eneur %d\n", value);
  }else{
    if (isEmpty(q))
    {
      q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued -> %d\n", value);
  }
  
}

// Dequeue an element
void dequeue(struct Queue *q) {
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
  } else {
    item = q->items[q->front];
    if(q-> front == q->rear){
      q->front = -1;
      q->rear = -1;
    }else{
      q->front++;
    }
    printf("Dequeued %d\n", item);
  }
  
}

int main () {
  struct Queue q;
  initializeQueue(&q);

  enqueue(&q, 1);
  enqueue(&q, 22);
  enqueue(&q, 33);
  enqueue(&q, 44);
  enqueue(&q, 55);
  enqueue(&q, 66); // full


  display(&q);

  dequeue(&q);
  dequeue(&q);

  display(&q);

  enqueue(&q, 77); // wont happen as the queue is full
  //In a linear queue, even after dequeuing elements, the rear index remains at its maximum value (MAX - 1), and the queue cannot reuse the vacated spaces. This is a limitation of a linear queue implementation. To fix this issue, we need to implement a circular queue, where the rear and front indices wrap around when they reach the end of the array.

  display(&q);
}