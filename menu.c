#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *link;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof (struct Node));
    newNode ->data=data;
    newNode ->link=NULL;
    return newNode; 
}
//Function to insert Node at the beginning of the list.
struct Node* insertAtBeginning(struct Node* head,int data)
{
    struct Node* newNode=createNode(data);
    newNode -> link = head;
    return newNode;
}
//function to delete Node from the beginning of the list.
struct Node* deleteFromBeginning(struct Node*head)
{
    if(head == NULL)
    {
        printf("List is empty.");
        return NULL;
    }
    struct Node* temp=head;
    head=head->link;
    free(temp);
    return head;
}

//Function to traverse & print the linked list.
void traverse(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main()
{
    struct Node* head=NULL;
    int choice,data;

    while(1){
    printf("\nMENU\n");
    printf("1. Insert Node At Beginning.\n");
    printf("2. Delete Node from Beginning.\n");
    printf("3.Traverese Linked List.\n");
    printf("4. Quit.\n");

    printf("Enter the choice:");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("Enter data for the new node: ");
            scanf("%d",&data);
            head = insertAtBeginning(head,data);
        break;

        case 2:
            head = deleteFromBeginning(head);
        break;

        case 3:
            traverse(head);
        break;

        case 4:
            exit(0);
        
        default:
        printf("INVALID CHOICE..PLEASE TRY AGAIN");
    }
    }
return 0;
}