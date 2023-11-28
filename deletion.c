#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL) {
    return NULL;
  }

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node to be deleted has value equal to key

    // Case 1: Node has no children
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }

    // Case 2: Node has one child
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    // Case 3: Node has two children
    struct Node *successor = findMin(root->right);
    root->data = successor->data;
    root->right = deleteNode(root->right, successor->data);
  }

  return root;
}

struct Node *findMin(struct Node *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

void printTree(struct Node *root) {
  if (root == NULL) {
    return;
  }

  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}

int main() {
  struct Node *root = newNode(10);
  root->left = newNode(5);
  root->right = newNode(15);
  root->left->left = newNode(2);
  root->left->right = newNode(7);
  root->right->right = newNode(20);

  printf("Original tree: ");
  printTree(root);

  root = deleteNode(root, 15);
  printf("\nTree after deleting 15: ");
  printTree(root);

  return 0;
}