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