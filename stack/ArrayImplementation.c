#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 100

// strecture of stack

struct Stack {
  int top;
  int items[CAPACITY];
};

void initializeStack(struct Stack *stack){
  stack->top = -1;
};

int isFull (struct Stack *stack){
  if (stack -> top == CAPACITY - 1 ){
    return 1;
  } else {
    return 0;
  }
}

int isEmpty (struct Stack *stack){
  if (stack -> top == -1){
    return 1;
  } else {
    return 0;
  }
}

int peek(struct Stack *stack){
  if (isEmpty(stack)){
    printf("Stack is empty, UNDERFLOW \n");
    return -1;
  } else {
    return stack -> items[stack -> top];
  }
}

void display(struct Stack *stack){
  if (isEmpty(stack)){
    printf("\n Stack is empty, UNDERFLOW \n");
    return;
  } else {
    printf("\n Stack elements are: ");
    for (int i = 0; i <= stack -> top; i++){
      printf("%d \t", stack -> items[i]);
    }
    printf("\n");
  }
}

void push(struct Stack *stack, int data){
  if (isFull(stack))
  {
    printf("\n Stack is full, OVERFLOW \n");
    return;
  } else {
    stack -> top++;
    stack -> items[stack -> top] = data;
  }
  
}

int main (){
  struct Stack stack;
  initializeStack(&stack);
}
