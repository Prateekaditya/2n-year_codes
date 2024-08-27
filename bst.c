#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int info;
  struct node *lchild,*rchild;
}node;
node *root=NULL;
node * makenode(){
    node *nw;
    nw=(node *)malloc(size(node));
    nw->lchild=NULL;
    nw->rchild=NULL;
    return (nw);
}
int insert(int data){
    node *p,*nw,*q;
    nw=makenode();
    nw->info=data;
    p=root;
    while(p!=NULL){
        {q=p;
        if (p->info>data)
        {
            p=p->lchild;
        }
        else{
            p=p->rchild;
        }}
        if(q->info>data){
            q->lchild=nw;
        }
        else{q->rchild=nw;
        }
    }
}
int main()
{
    int data;
    printf("enter data;");
    scanf("%d",&data);
    insert(data)
  
    return 0;

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