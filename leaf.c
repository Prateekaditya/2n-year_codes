#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

int countLeafNodes(struct Node *root) {
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    return 1;
  }
  int leafNode=countLeafNodes(root->left) + countLeafNodes(root->right);
  return leafNode;
}

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

int main() {
  struct Node *root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(15);
  root->left->left = createNode(2);
  root->left->right = createNode(7);
  root->right->left = createNode(12);
  root->right->right = createNode(20);

  int leafNodeCount = countLeafNodes(root);
  printf("Number of leaf nodes: %d\n", leafNodeCount);

  return 0;
}