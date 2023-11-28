//Create a BST of n order and implement a menu of post,in and preorder on it;
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node * newnode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int data){
    if(root==NULL){
        return newnode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else{
        printf("Duplicate data %d this data already exits in BST\n",data);
}
    return root;
}

void preorder( struct node * root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    int data,n,i,choice;
    printf("Enter the number of nodes to be enter:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter data:");
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("1.Preorder Traversal\n");
    printf("2.Postorder Traversal\n");
    printf("3.Inorder Traversal\n");
    printf("4.Exit");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&choice);
       switch(choice){
        case 1:
        printf("Preorder Traversal is:\n");
        preorder(root);
        break;
        case 2:
        printf("Postorder Traversak is:\n");
        postorder(root);
        break;
        case 3:
        printf("Inorder Traversal is:\n");
        inorder(root);
        break;
        case 4:
        printf("EXIT---------\n");
        exit(0);
        default:
        printf("INVALID CHOICE\n");
        break;
        
       }
    }
    return 0;
}