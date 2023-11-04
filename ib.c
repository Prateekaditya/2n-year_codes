#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *add_beg(struct node *head,int d){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;

}
int main(){
    struct node *head=malloc(sizeof(struct node));
    printf("enter the data for the node:\n");
    scanf("%d",&head->data);
    head->link=NULL;
    struct node *ptr=malloc(sizeof(struct node));
    printf("enter the data for the node:\n");
    scanf("%d",&ptr->data);
    ptr->link=NULL;
    head->link=ptr;
   int data;
   printf("enter the data to be insert at beginning:\n");
   scanf("%d",&data);
   head=add_beg(head,data);
   ptr=head;
   while(ptr!=NULL){
    printf("%d->",ptr->data);
    ptr=ptr->link;
   }
   printf("NULL");
   return 0;
}