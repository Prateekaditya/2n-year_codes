#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    int data;
    struct node* right;
};
struct node * create(){
    int x;
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Data:");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter left child %d ",x);
    newnode->left=create();
    printf("Enter right child %d ",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void main(){
    struct node* root=NULL;
    root=create();
    printf("Inorder is:");
    inorder(root);
}
