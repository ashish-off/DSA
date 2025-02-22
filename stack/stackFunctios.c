#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


int isEmpty(struct Node* top) {
    return (top == NULL);
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
    newNode->next = *top; 
    *top = newNode;      
    printf("%d pushed\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top; 
    int poppedValue = temp->data;
    *top = (*top)->next; 
    free(temp);     
    return poppedValue;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return top->data;
}

void printStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* top = NULL; 

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printStack(top); 

    printf("Top element: %d\n", peek(top));

    printf("%d popped from the stack\n", pop(&top)); 
    printStack(top); 

    printf("%d popped from the stack\n", pop(&top)); 
    printStack(top); 

    printf("%d popped from the stack\n", pop(&top)); 
    printStack(top); 

    printf("%d popped from the stack\n", pop(&top)); 

    return 0;
}