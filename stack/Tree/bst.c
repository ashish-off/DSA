#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct Node *search(struct Node *root, int key)
{
  if (root == NULL || root->data == key)
    return root;
  if (key < root->data)
    return search(root->left, key);
  else
    return search(root->right, key);
}

struct Node *insert(struct Node *root, int value)
{
  if (root == NULL)
    return createNode(value);
  if (value < root->data)
    root->left = insert(root->left, value);
  else if (value > root->data)
    root->right = insert(root->right, value);
  return root; // Return unchanged root if duplicate
}

struct Node *minValueNode(struct Node *node)
{
  struct Node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
  if (root == NULL)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else
  {
    // Case 1: No child or one child
    if (root->left == NULL)
    {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    // Case 3: Two children
    struct Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void inorderTraversal(struct Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

int main()
{
  struct Node *root = NULL;  // struct Node root = NULL; 
  root = insert(root, 50);//&root = insert(&root , 30); 
  insert(root, 30); 
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorderTraversal(root); // Output: 20 30 40 50 60 70 80

  printf("\nDelete 20 (leaf node)\n");
  root = deleteNode(root, 20);
  inorderTraversal(root); // Output: 30 40 50 60 70 80

  printf("\nDelete 30 (node with one child)\n");
  root = deleteNode(root, 30);
  inorderTraversal(root); // Output: 40 50 60 70 80

  printf("\nDelete 50 (node with two children)\n");
  root = deleteNode(root, 50);
  inorderTraversal(root); // Output: 40 60 70 80

  return 0;
}