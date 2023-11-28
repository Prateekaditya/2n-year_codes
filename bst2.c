#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
  struct node *left, *right;
};
struct node *newNode(int data)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
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
struct node *findMin(struct node *root)
{
  if (root == NULL) {
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}
struct node *deleteNode(struct node *root, int data)
{
  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    // Node to be deleted found
    // Check if the node has no children
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    // Check if the node has one child
if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else
 
if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Check if the node has two children
    struct node *successor = findMin(root->right);
    root->data = successor->data;
    root->right = deleteNode(root->right, successor->data);
  }

  return root;
}


void inOrderTraversal(struct node *root)
{
  if (root == NULL) {
    return;
  }
  inOrderTraversal(root->left);
  printf("%d\t ", root->data);
  inOrderTraversal(root->right);
}

int main()
{
  struct node *root =NULL;

 int data,n,i;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data for BST:");
        scanf("%d",&data);
        root=insert(root,data);
    }
      printf("In-order traversal: ");
  inOrderTraversal(root);
  // Deleting nodes from the BST
   int j,m;
   printf("Enter the no.of nodes to be deleted:");
   scanf("%d",&m);
   for(j=0;j<m;j++){
    printf("Enter the data to be deleted:");
    scanf("%d",&data);
    root=deleteNode(root,data);
   }
  // In-order traversal of the modified BST
  printf("In-order traversal: ");
  inOrderTraversal(root);

  return 0;
}