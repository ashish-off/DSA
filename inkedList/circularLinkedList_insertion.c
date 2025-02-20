#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void display(struct Node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *current = head;
  do
  {
    printf("%d -> ", current->data);
    current = current->next;
  } while (current != head);
  printf("(head)\n");
}

void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
  {
    *head = newNode;
    newNode->next = *head;
  }
  else
  {
    struct Node *temp = *head;
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
  }
}

void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
      *head = newNode;
      newNode->next = *head; 
  } else {
      struct Node* last = *head;
      while (last->next != *head) {
          last = last->next; 
      }
      last->next = newNode;  
      newNode->next = *head; 
  }
}

int main()
{
  struct Node *head = NULL;

  printf("\n After inserting at the beginning: \n");
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);
  display(head);

  printf("\n After inserting at the end: \n");
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);
  display(head);


}