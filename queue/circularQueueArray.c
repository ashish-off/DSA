#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct Queue
{
  int front;
  int rear;
  int items[MAX];
};

// Initialize the queue
void initializeQueue(struct Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue *q) {
  return q->front == -1;
}
//The condition q->front == -1 is independent of the circular nature of the queue and works correctly in all cases.


// Check if the queue is full
bool isFull(struct Queue *q)
{
  return (q->rear + 1) % MAX == q->front;
}

// Display the queue
void display(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("\nFront index -> %d\n", q->front);
    printf("Items -> ");
    int i = q->front;
    do
    {
      printf("%d ", q->items[i]);
      i = (i + 1) % MAX; // Circular increment
    } while (i != (q->rear + 1) % MAX);

    // while (1)
    // {
    //   printf("%d ", q->items[i]);
    //   if (i == q->rear)
    //   {
    //     break;
    //   }
    //   i = (i + 1) % MAX; // Circular increment
    // }

    printf("\nRear index -> %d\n", q->rear);
  }
}

// Enqueue an element
void enqueue(struct Queue *q, int value)
{
  if (isFull(q))
  {
    printf("Queue is full, cannot enqueue %d\n", value);
  }
  else
  {
    if (isEmpty(q))
    {
      q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value;
    printf("Enqueued -> %d\n", value);
  }
}

// deque a element

void dequeue(struct Queue *q)
{
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty, cannot dequeue\n");
  }
  else
  {
    item = q->items[q->front];
    if (q->front == q->rear) // only one element(last element dequeued)
    {
      q->front = q->rear = -1;
    }
    else
    {
      q->front = (q->front + 1) % MAX; // circular increment
    }
    printf("Dequeued -> %d\n", item);
  }
}

int main()
{
  struct Queue q;
  initializeQueue(&q);

  enqueue(&q, 11);
  enqueue(&q, 22);
  enqueue(&q, 33);
  enqueue(&q, 44);
  enqueue(&q, 55);
  enqueue(&q, 66); // full
  display(&q);

  dequeue(&q);
  dequeue(&q);
  
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);


  display(&q);

  enqueue(&q, 77);
  enqueue(&q, 88);
  enqueue(&q, 99);
  display(&q);
  return 0;
}