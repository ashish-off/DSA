#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// traverse

void display(struct Node *temp)
{
  while (temp != NULL)
  {
    printf("Element: %d \n", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// insert at begining of node
void insertAtBegin(struct Node **head, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}
// insert at end of node
void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  struct Node *temp = *head;

  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

// insert at nth position(index)

void insertAtPosition(struct Node **head, int data, int index)
{
  if (index < 1) {
    printf("Invalid position. Position should be >= 1.\n");
    return;
}
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->data = data;


  struct Node *temp = *head;
  int i = 1;

  if (index == 1)
  {
    insertAtBegin(head, data);
    return;
  }
  else
  {

    while (i != index - 1 && temp != NULL)
    {
      temp = temp->next;
      i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
  }
}

int main()
{
  struct Node *head = NULL;
  insertAtBegin(&head, 3);
  insertAtBegin(&head, 6);
  insertAtBegin(&head, 8);
  display(head);

  // printf("\n inserting at end: \n");
  // insertAtEnd(&head, 88);
  // insertAtEnd(&head, 899);
  // display(head);

  // printf("\n inserting at position: \n");
  // insertAtPosition(&head, 333,2);
  // display(head);

  // printf("\n inserting at end: \n");
  // insertAtEnd(&head, 3454);
  // insertAtEnd(&head, 2992);
  // insertAtEnd(&head, 4545);
  // display(head);
}