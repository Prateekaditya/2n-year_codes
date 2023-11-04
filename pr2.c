#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *del_last(struct node * head){
    if (head==NULL)
    printf("LINKED LIST IS EMPTY");
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2=head;
        while(temp->link!=NULL){
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
    return head;
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;


    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;


    current = malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;


    current=malloc(sizeof(struct node));
    current->data=56;
    current->link=NULL;
    head->link->link->link=current;
    head=del_last(head);
    current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->link;
    }
    printf("NULL");
 return 0;
}