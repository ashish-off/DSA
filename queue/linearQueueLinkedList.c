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

// Function to remove an element from the queue (Dequeue)
int dequeue(struct Queue* q) {
  if (isEmpty(q)) {
      printf("Queue is empty! Cannot dequeue\n");
      return -1;
  } else {
      // Remove the front node and update the front pointer
      struct Node* temp = q->front;
      int dequeuedValue = temp->data;
      q->front = q->front->next;

      // If the queue becomes empty after dequeue, update the rear pointer
      if (q->front == NULL) {
          q->rear = NULL;
      }

      free(temp); // Free the memory of the dequeued node
      printf("Dequeued %d from the queue\n", dequeuedValue);
      return dequeuedValue;
  }
}


int main (){

}