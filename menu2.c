#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    return newnode;
}
struct node* insertatbeginning(struct node *head,int data){
    struct node *newnode=createnode(data);
    newnode->link=head;
    return newnode;
}

int main(){
struct node *head=NULL;
int choice,data;

while(1){
  printf("\n----Menu-----\n");
  printf("1.insert at beginning.\n");
  printf("2.insert at last.\n");
  printf("3.insert at certain position.\n");
  printf("4.count no.of nodes.\n");
  printf("5.print the linked list.\n");
  printf("6.exiting.....\n");

  printf("Enter your choice:");
  scanf("%d",&choice);

  switch(choice){
    case 1:{
        printf("Enter the data for the new node:");
        scanf("%d",&data);
        head=insertatbeginning(head,data);

    }
    case 2:{
        
    }
  }

}
    return 0;
}