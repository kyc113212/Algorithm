#include <stdio.h>
#include <malloc.h>

typedef struct Node {
 int data;
 struct Node* left;
 struct Node* right;
 struct Node* parent;
}Node;

typedef struct Tree {
 Node* root;
 int depth;
 int node_count;
}Tree;

void initTree(Tree* tree) {
 tree->root = NULL;
 tree->depth = 0;
 tree->node_count = 0;

}

void printPreOrder(Node *c_node) {
 if (c_node) {
  printf("%d ", c_node->data);
  printPreOrder(c_node->left);
  printPreOrder(c_node->right);
 }
 return;
}


Node* searchNode(Node* node, int value) {
 while (node) {
  if (value == node->data) {
   printf("find %d\n", value);
   return node;
  }
  else if (value > node->data) {
   if (node->right == NULL)
    return NULL;
   node = node->right;
  }
  else if (value < node->data) {
   if (node->left == NULL)
    return NULL;
   node = node->left;
  }
 }

 return NULL;
}

void addNode(Tree* tree, int value) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 if (searchNode(tree->root, value) != NULL) {
  printf("already exist data\n");
  return;
 }
 if (tree->root == NULL) {
  newNode->data = value;
  tree->root = newNode;
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->parent = NULL;
  tree->node_count++;
  return;
 }
 else {
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = value;
  Node* curr = tree->root;

  while (1) {
   if (curr->data > value) {
    if (curr->left == NULL) {
     curr->left = newNode;
     newNode->parent = curr;
     return;
    }
    curr = curr->left;
   }
   else if (curr->data < value) {
    if (curr->right == NULL) {
     curr->right = newNode;
     newNode->parent = curr;
     return;
    }
    curr = curr->right;
   }
  }
 }
 return;

}

Node* findMinNode(Node* node) {
 Node* tmp = node;
 while (tmp->left != NULL) {
  tmp = tmp->left;
 }
 return tmp;
}

void deleteNode(Node *node, int value) {
 Node* temp_node = searchNode(node, value);
 if (node == NULL)
  return;
 
}

int main() {

 Tree tree;
 initTree(&tree);

 addNode(&tree, 9);
 addNode(&tree, 11);
 addNode(&tree, 5);
 addNode(&tree, 6);
 addNode(&tree, 14);
 addNode(&tree, 2);
 addNode(&tree, 10);
 addNode(&tree, 1);
 addNode(&tree, 56);
 addNode(&tree, 8);
 Tree* temp = &tree;
 printPreOrder(temp->root);
 printf("\n");
 deleteNode(temp->root, 5);

 return 0;
}
