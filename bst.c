#include<stdio.h>
#include<stdlib.h>
typedef struct n{
  int info;
  struct n *lchild,*rchild;
}node;
node * makenode(){
    node *nw;
    nw=(node *)malloc(size(node));
    nw->lchild=NULL;
    nw->rchild=NULL;
    return (nw);
}

int main()
{
    node *root=NULL;
}