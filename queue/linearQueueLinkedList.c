#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node *front, *rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
  q->front = NULL;
  q->rear = NULL;
}

bool isEmpty(struct Queue* q) {
  return q->front == NULL;
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue* q, int value) {

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (isEmpty(q)) {
      // If the queue is empty, set both front and rear to the new node
      q->front = newNode;
      q->rear = newNode;
  } else {
      // Add the new node at the rear and update the rear pointer
      q->rear->next = newNode;
      q->rear = newNode;
  }
  printf("Enqueued %d to the queue\n", value);
}


int main (){

}