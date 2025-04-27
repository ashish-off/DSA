#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Check if stack is empty
bool isEmpty()
{
  return (top == -1);
}

// Check if stack is full
bool isFull()
{
  return (top == MAX - 1);
}

// Push an element
void push(int x)
{
  if (isFull())
  {
    printf("Stack Overflow!\n");
    return;
  }
  stack[++top] = x;
  printf("%d pushed to stack.\n", x);
}

// Pop an element
int pop()
{
  if (isEmpty())
  {
    printf("Stack Underflow!\n");
    return -1;
  }
  return stack[top--];
}

// Peek the top element
int peek()
{
  if (isEmpty())
  {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack[top];
}

void printStack()
{
  if (isEmpty())
  {
    printf("Stack is empty.\n");
    return;
  }
  for (int i = 0; i <= top; i++){
    printf("%d -> ", stack[i]);
  }
}

int main()
{
  push(10);
  push(20);
  push(30);
  printf("Top element: %d\n", peek());
  printf("%d popped from stack.\n", pop());
  printf("Top element after pop: %d\n", peek());
  printStack();
  return 0;
}
