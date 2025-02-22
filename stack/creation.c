#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
  int data;
  struct Node *next;
};

int isEmpty(struct Node *top)
{
  return (top == NULL);
}

// Function to push an element onto the stack
void push(struct Node **top, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  newNode->next = *top;
  *top = newNode;
  printf("%d pushed\n", data);
}

void printStack(struct Node *top)
{
  if (isEmpty(top))
  {
    printf("Stack is empty\n");
    return;
  }
  struct Node *current = top;
  printf("Stack: ");
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main()
{
  struct Node *top = NULL;

  push(&top, 10);
  push(&top, 20);
  push(&top, 30);

  printStack(top);
  return 0;
}