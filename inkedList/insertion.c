
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertAtBeg(struct Node *(*head), int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->next = *head;
  temp->data = data;

  *head = temp;
}

// Function to traverse and display the linked list
void display(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("Element: %d \n", ptr->data);
    ptr = ptr->next;
  }
}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *four;

  // Allocate memory for nodes
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  four = (struct Node *)malloc(sizeof(struct Node));

  // Check if memory allocation succeeded
  if (head == NULL || second == NULL || third == NULL || four == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1; // Exit the program with an error code
  }

  // Link nodes
  head->data = 10;
  head->next = second;

  second->data = 145;
  second->next = third;

  third->data = 700;
  third->next = four;

  four->data = 200;
  four->next = NULL; // Terminate the linked list

  // Traverse and display the linked list
  display(head);

  printf("\n after inserting at beg \n");

  insertAtBeg(&head, 999);

  display(head);
  display(head);

  return 0;
}