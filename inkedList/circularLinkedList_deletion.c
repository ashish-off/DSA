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
    struct Node *last = *head;
    while (last->next != *head)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
    *head = newNode;
  }
}

void deleteAtBeg(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty, nothing to delete.\n");
    return;
  }
  struct Node *temp = *head;
  if (temp->next == *head)
  {
    // Only one node in the list
    free(temp);
    *head = NULL;
  }
  else
  {
    // Traverse to the last node
    struct Node *last = *head;
    while (last->next != *head)
    {
      last = last->next;
    }
    *head = temp->next; // Move head to the next node
    last->next = *head; // Update the last node's next pointer
    free(temp);         // Free the old head
  }
  printf("Deleted from the beginning.\n");
}

void deleteAtEnd(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty, nothing to delete.\n");
    return;
  }
  struct Node *temp = *head;
  struct Node *secondLast = NULL;

  if (temp->next == *head)
  {
    // Only one node in the list
    free(temp);
    *head = NULL;
  }
  else
  {
    // Traverse to the last node
    while (temp->next != *head)
    {
      secondLast = temp;
      temp = temp->next;
    }
    secondLast->next = *head; // Update the second last node's next pointer
    free(temp);               // Free the last node
  }
  printf("Deleted from the end.\n");
}

void deleteAtPosition(struct Node **head, int position)
{
  if (*head == NULL)
  {
    printf("List is empty, nothing to delete.\n");
    return;
  }

  if (position < 1)
  {
    printf("Invalid position. Position should be >= 1.\n");
    return;
  }

  struct Node *temp = *head;

  if (position == 1)
  {
    // Delete from the beginning
    deleteAtBeg(head);
    return;
  }

  // Traverse to the node before the given position
  int i = 1;
  while (i < position - 1 && temp->next != *head)
  {
    temp = temp->next;
    i++;
  }

  if (i != position -1 || temp->next == *head)
  {
    printf("Invalid position. Position exceeds the length of the list.\n");
    return;
  }

  // Delete the node
  // temp->next = temp->next->next;
  struct Node *nodeToDelete = temp->next;
   temp->next = nodeToDelete->next;
  free(nodeToDelete);
  printf("Deleted at position %d.\n", position);
}

int main()
{
  struct Node *head = NULL;

  // Insert elements into the circular linked list
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);
  insertAtBeginning(&head, 40);
  insertAtBeginning(&head, 50);

  printf("Initial list: ");
  display(head); // Output: 50 -> 40 -> 30 -> 20 -> 10 -> HEAD

  // Delete from the beginning
  deleteAtBeg(&head);
  printf("List after deleting from the beginning: ");
  display(head); // Output: 40 -> 30 -> 20 -> 10 -> HEAD

  // Delete from the end
  deleteAtEnd(&head);
  printf("List after deleting from the end: ");
  display(head); // Output: 40 -> 30 -> 20 -> HEAD

  // Delete at a specific position
  deleteAtPosition(&head, 2);
  printf("List after deleting at position 2: ");
  display(head); // Output: 40 -> 20 -> HEAD

  // Attempt to delete at an invalid position
  deleteAtPosition(&head, 5); // Invalid position
  printf("List after attempting to delete at invalid position: ");
  display(head); // Output: 40 -> 20 -> HEAD

  return 0;
}