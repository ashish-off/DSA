#include<stdio.h>


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

void deleteAtBegin(struct Node **head){
  
  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  
  struct Node *temp = *head;
  temp = temp -> next;
  *head = temp;

}

int main () {
  struct Node *head = NULL;
  insertAtBeg(&head, 22);
  insertAtBeg(&head, 44);
  insertAtBeg(&head, 66);
  insertAtBeg(&head, 99);

  display(head);

  printf("\n delete at begining");

  deleteAtBegin(&head);
  display(head);

}