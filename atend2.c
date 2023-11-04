#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;

};

void traverse(struct Node* head){
    if(head==NULL){
    printf("Linked List is empty.");
    }
    printf("\nLinked List: ");
    while(head !=NULL ){
        printf("%d ->",head->data);
        head=head->link;
    }
    printf("NULL\n");

}

struct Node* addAtEnd(struct Node* ptr, int data)
{
    struct Node *temp=malloc(sizeof(struct Node));
    temp ->data=data;
    temp ->link=NULL;

    ptr->link=temp;
    return temp;
}

int main(){
    struct Node *head=malloc(sizeof(struct Node));
    head->data=45;
    head->link=NULL;

    struct Node* ptr=head;
    ptr=addAtEnd(ptr,98);
    ptr=addAtEnd(ptr,67);
    ptr=addAtEnd(ptr,45);

    ptr=head;

    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }

    traverse(head);
    return 0;
}