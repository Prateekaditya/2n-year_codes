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
struct node *findmin(struct node *root){
  if(root==NULL){
    return NULL;
  }
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}
struct node * delete(struct node *root,int data){
  if(root==NULL){
    return NULL;
  }
  if(data<root->data){
    root->left=delete(root->left,data);
  }
  else if(data>root->data){
    root->right=delete(root->right,data);
  }
  else{
    //no child
    if(root->left==NULL && root->right==NULL){
      free(root);
      return NULL;
    }
    //one child
    if(root->left==NULL){
      struct node *temp=root->right;
      free(root);
      return temp;
    }
    if(root->right==NULL){
      struct node *temp=root->left;
      free(root);
      return temp;
    }
    //two child
    struct node *successor=findmin(root->right);
    root->data=successor->data;
    root->right=delete(root->right,successor->data);
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
   printf("\nEnter the no.of nodes to be deleted:");
   scanf("%d",&m);
   for(j=0;j<m;j++){
    printf("Enter the data to be deleted:");
    scanf("%d",&data);
    root=delete(root,data);
   }
  // In-order traversal of the modified BST
  printf("In-order traversal: ");
  inOrderTraversal(root);

  return 0;
}