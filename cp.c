#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct Node* addend(struct Node* ptr, int data)
{
    struct Node *temp=malloc(sizeof(struct Node));
    temp ->data=data;
    temp ->link=NULL;

    ptr->link=temp;
    return temp;
}
void addpos(struct node *head,int data ,int pos){
 struct node *ptr=head;
 struct node *ptr2=malloc(sizeof(struct node));
 ptr2->data=data;
 ptr2->link=NULL;
 pos--;
 while(pos!=1){
   ptr=ptr->link;
   pos--;
 }
 ptr2->link=ptr->link;
 ptr->link=ptr2;
}
int main(){
struct node *head=malloc(sizeof(struct node));
printf("Enter the node");
scanf("%d",&head->data);
head->link=NULL;
int a, b;
printf("Enter the values of nodes");
scanf("%d%d",&a,&b);
addend(head,a);
addend(head,b);
int data,position;
printf("Enter the data and postion:");
scanf("%d%d",&data,&position);
addpos(head,data,position)
struct node *ptr=head;
while(ptr!=NULL){
    printf("%d",ptr->data);
    ptr=ptr->link;
}
return 0;
}