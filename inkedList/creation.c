#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

// traverse

void display(struct Node * ptr){
while (ptr != NULL)
{
  printf("Element: %d \n", ptr -> data);
  ptr = ptr-> next;
}

}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *four;

  // allocate memory
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  four = (struct Node *)malloc(sizeof(struct Node));

  // Check if memory allocation succeeded (optional)
  if (head == NULL || second == NULL || third == NULL || four == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1; 
  }

  // linking first and second node
  head->data = 10;
  head->next = second;
  
  // linking second and third node
  second->data = 145;
  second->next = third;
  // linking third and fourth node
  third->data = 700;
  third->next = four;

  // terminating linkedList at fourth node
  four->data = 200;
  four->next = NULL;

  // traverse

  display(head);

}