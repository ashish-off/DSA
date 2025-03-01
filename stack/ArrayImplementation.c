#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

// strecture of stack

struct Stack
{
  int top;
  int items[CAPACITY];
};

void initializeStack(struct Stack *stack)
{
  stack->top = -1;
};

int isFull(struct Stack *stack)
{
  if (stack->top == CAPACITY - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty(struct Stack *stack)
{
  if (stack->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int peek(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty, UNDERFLOW \n");
    return -1;
  }
  else
  {
    return stack->items[stack->top];
  }
}

void display(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty, UNDERFLOW \n");
    return;
  }
  else
  {
    printf("\nStack elements are: ");
    for (int i = stack->top; i >= 0  ; i--)
    {
      printf("%d   ", stack->items[i]);
    }
    printf("\n");
  }
}

void push(struct Stack *stack, int data)
{
  if (isFull(stack))
  {
    printf(" Stack is full, OVERFLOW \n");
    return;
  }
  else
  {
    stack->top++;
    stack->items[stack->top] = data;
    printf("%d is pushed \n", data);
  }
}

// without using pointers

struct Stack pushstack(struct Stack stack, int data)
{
  if (isFull(&stack))
  {
    printf(" Stack is full, OVERFLOW \n");
    return stack;
  }
  else
  {
    stack.top++;
    stack.items[stack.top] = data;
    printf("%d is pushed \n", data);
    return stack;
  }
}

void pop(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty, UNDERFLOW \n");
    return;
  
  }else {
    printf("%d is popped \n", stack->items[stack->top]);
    stack->top--;
  }
}

int main()
{
  struct Stack stack;
  initializeStack(&stack);

  push(&stack, 10);
  push(&stack, 102);
  push(&stack, 12);
  push(&stack, 312);

  display(&stack);

  pop(&stack);
  pop(&stack);
  display(&stack);

  printf("Top element is %d \n", peek(&stack));

  stack = pushstack(stack, 2222);
  display(&stack);
}
