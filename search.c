#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *newnode(int data){
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
        printf("Duplicate data %d it already exists in the bst\n");
    }
    return root;
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
struct node *search(struct node *root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
int main(){
struct node *root=NULL;
int data,n,i;
printf("Enter the numbers of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter data:");
    scanf("%d",&data);
    root=insert(root,data);
}
printf("INORDER TRAVERSAL:\n");
inorder(root);
int key;
printf("\nEnter the value to be searched:");
scanf("%d",&key);
struct node *found=search(root,key);
    if(found!=NULL){
        printf("key %d found in BST\n",key);
    }
    else{
        printf("Key %d not found in BST\n",key);
    }

return 0;
}