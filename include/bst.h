// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <string>
template < typename T >
class BST {
 private :
struct Node {
T value;
int count;
Node *left;
Node *right;
};
Node* root;
Node* addNode(Node* root, T val) {
if (root == nullptr) {
root = new Node;
root->value = val;
root->count = 1;
root->left = root->right = nullptr;
} else if (root->value > val) {
root->left = addNode(root->left, val);
} else if (root->value < val) {
root->right = addNode(root->right, val);
} else {
root->count++;
}
return root;
}

int depthTree(Node* root) {
  if (root ==nullptr) {
  return 0;
  } else {
int L = depthTree(root->left);
int R = depthTree(root->right);
if (L > R) {
return L + 1;
} else {
return R + 1;
}
}
}
int searchNode(Node* root, T val) {
if (root ==nullptr) {
  return 0;
} else if (root->value == val) {
return root->count;
} else if (root->value > val) {
return searchNode(root->left, val);
} else {
return searchNode(root->right, val);
}
}
 public :
BST() {
root = nullptr;
}
void add(T value) {
root = addNode(root, value);
}
int depth() {
return depthTree(root)-1;
}
int search(T value) {
return searchNode(root, value);
}
};

#endif  // INCLUDE_BST_H_
