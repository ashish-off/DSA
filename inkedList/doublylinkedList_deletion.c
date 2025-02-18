#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void display(struct Node *temp)
{
  if (temp == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  while (temp != NULL)
  {
    printf("Element: %d \n", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

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

void deleteAtBegin(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  struct Node *temp = *head;
  *head = temp->next;

  // If the new head exists, update its prev pointer to NULL
  if (*head != NULL)
  {
    (*head)->prev = NULL;
  }

  free(temp);
}

void deleteAtEnd(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  // If the list has only one node
  if ((*head)->next == NULL)
  {
    free(head);
    *head = NULL;
    return;
  }

  struct Node *temp = *head;
  // Traverse to the second-to-last node
  while ((temp->next)->next != NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void deleteAtIndex(struct Node **head, int index){
  if (*head == NULL)
  {
    printf("empty List");
    return;
  }

  if (index == 1)
  {
    deleteAtBegin(head);
    return;
  }

  int i = 1;
  struct Node *temp = *head;

  while (i != index -1 && temp != NULL)
  {
    temp = temp -> next;
    i++;
  }
    // Check if the index is out of bounds
    if (temp == NULL || temp->next == NULL)
    {
      printf("Index out of bounds.\n");
      return;
    }
  
  struct Node *nodeToDelete = temp -> next;
    temp -> next = nodeToDelete -> next;
    if (nodeToDelete->next != NULL)
    {
      nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
}

int main()
{
  struct Node *head = NULL;

  insertAtBegin(&head, 22);
  insertAtBegin(&head, 77);
  insertAtBegin(&head, 55);
  insertAtBegin(&head, 33);
  display(head);

  // printf("After delete at begining :  \n");
  // deleteAtBegin(&head);
  // display(head);

  // printf("After delete at ending :  \n");
  // deleteAtEnd(&head);
  // display(head);

  printf("After delete at index :  \n");
  deleteAtIndex(&head, 2);
  display(head);
}