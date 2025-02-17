#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertAtBeg(struct Node *(*head), int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}
void display(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("Element: %d \n", ptr->data);
    ptr = ptr->next;
  }
}

// delete at begining

void deleteAtBegin(struct Node **head)
{

  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  else if ((*head)->next == NULL)
  {
    *head = NULL;
    free(*head);
    return;
  }

  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// delete at index

void deleteAtIndex(struct Node **head, int index)
{
  struct Node *temp = *head;
  int i = 1;

  if (index == 1)
  {
    deleteAtBegin(head);
    return;
  }
  else if (*head == NULL || index < 1)
  {
    printf("Invalid index or empty list\n");
    return;
  }

  while (i != (index - 1))
  {
    temp = temp->next;
    i++;
  }
  // temp->next = (temp->next)->next;
  struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; 
    free(nodeToDelete);

}

void deleteAtEnd(struct Node **head)
{

  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  if ((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;
    return;
  }

  struct Node *temp = *head;
  while ((temp->next)->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = NULL;
  free((temp->next));
}

void deleteByValue(struct Node **head, int value){
  if (*head == NULL) {
    printf("List is empty\n");
    return;
}

  struct Node *temp = *head;
  struct Node *prev = NULL;

     // If the head node itself holds the value to be deleted
     if (temp != NULL && temp->data == value) {
      *head = temp->next; // Move head to the next node
      free(temp); // Free old head
      return;
  }

   // Search for the node to be deleted
  while (temp != NULL && temp -> data != value){
    prev = temp;
    temp = temp -> next;
  }

    // If the value is not found
  if (temp == NULL){
    printf("Value not found in the list\n");
    return;
  }

  prev -> next = temp -> next;
  free(temp);
  
}

int main()
{
  struct Node *head = NULL;
  insertAtBeg(&head, 22);
  insertAtBeg(&head, 44);
  insertAtBeg(&head, 66);
  insertAtBeg(&head, 99);

  display(head);

  // printf("\n delete at begining \n");
  // deleteAtBegin(&head);
  // display(head);

  // printf("\n delete at index \n");
  // deleteAtIndex(&head, 3);
  // display(head);

  // printf("\n delete at end \n");
  // deleteAtEnd(&head);
  // display(head);

  printf("\n delete by value \n");
  deleteByValue(&head, 44);
  display(head);
}