//creating a binary search tree
//implementing 
//insert,delete,traversal,searching
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if(root == NULL) {
        root = createNode(data);
    } else if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* findMinNode(Node *root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node *root, int data) {
    if(root == NULL) {
        printf("Element Not Found\n");
    } else if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->right && root->left) {
            Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        } else {
            Node *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}

void searchNode(Node *root, int data) {
    if(root == NULL) {
        printf("Element Not Found\n");
    } else if(data < root->data) {
        searchNode(root->left, data);
    } else if(data > root->data) {
        searchNode(root->right, data);
    } else {
        printf("Element Found\n");
    }
}

void inorderTraversal(Node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, data;

    while(1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                searchNode(root, data);
                break;
            case 4:
                printf("Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}