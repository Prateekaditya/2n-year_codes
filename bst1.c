#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *left, *right;
};

struct node *newNode(int data)
 { struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node *insert(struct node *root, int data)
{
  if (root == NULL) {
    return newNode(data);
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  } else {
    printf("Duplicate data %d already exists in the BST\n", data);
  }

  return root;
}
void inOrderTraversal(struct node *root)
{
  if (root == NULL) {
    return;
  }
  inOrderTraversal(root->left);
  printf("%d ", root->data);
  inOrderTraversal(root->right);
}

int main() 
{
  struct node *root =NULL;
  int data,n,i;
  printf("Enter the numbers of nodes:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter data:");
    scanf("%d",&data);
  root = insert(root, data);}
  printf("In-order traversal: ");
  inOrderTraversal(root);

  return 0;
}