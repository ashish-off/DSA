
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

// inserting at beginning
void insertAtBeg(struct Node *(*head), int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}


// insert at index
void insertAtIndex(struct Node **head, int data, int index){
  struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;

  struct Node *temp = *head;
  int i =1;

  if (index ==1)
  {
    insertAtBeg(head, data);
    return ;
  }
  
  while (i != index -1 && temp != NULL)
  {
    temp = temp -> next;
    i++;
  }

  newNode -> next = temp->next;
  temp -> next = newNode;
  
}

// insert at end

void insertAtEnd(struct Node **head , int data){
  struct Node *newNode = (struct Node*) malloc( sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  struct Node *temp = *head;

  

  while (temp -> next != NULL)
  {
    temp = temp -> next;
  }
  temp -> next = newNode;

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
  struct Node *head = NULL;
insertAtBeg(&head, 1);
insertAtBeg(&head, 4);
insertAtBeg(&head, 6);

  // Traverse and display the linked list
  display(head);

  
  // insertAtBeg(&head, 999); // Pass the address of the head pointer
  // printf("\n after inserting at beg : \n");
  // display(head);
  
  // printf("\n after inserting at index : \n");
  // insertAtIndex(&head, 222,3);
  // display(head);
  
  printf("\n inserting at end : \n");
  insertAtEnd(&head,888);
  display(head);

  return 0;
}