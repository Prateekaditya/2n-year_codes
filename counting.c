#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count(struct node *head){
    int count=0;
    if(head==NULL)
     printf("LInked list is empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("%d",count);
}
int main(){
  struct node *head=malloc(sizeof(struct node));
  head->data=23;
  head->link=NULL;

  struct node *current=malloc(sizeof(struct node));
  current->data=65;
  current->link=NULL;
  head->link=current;

  current=malloc(sizeof(struct node));
  current->data=78;
  current->link=NULL;
  head->link->link=current;

  current = malloc(sizeof(struct node));
  current->data=89;
  current->link=NULL;
  head->link->link->link=current;

  count(head);
  return 0;
}