#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node * newnode(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
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
        printf("duplicate data %d already exist in the BST\n");
    }
    return root;
}
void inorder(struct node * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
int main(){
    struct node *root=NULL;
    int data,n,i;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data for BST:");
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("INORDER TRAVERSAL:");
    inorder(root);


    return 0;
}