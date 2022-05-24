// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
  T value;
  int count = 0;
  Node* left = nullptr;
  Node* right = nullptr;;
  };
Node* root;
Node* addNode(Node* root, const T& value1) {
if (root == nullptr) {
  root = new Node;
  root->value = value1;
  root->count = 1;
  root->left = root->right = nullptr;
  } else if (root->value < value1) {
    root->left = addNode(root->left, value1);
  } else if (root->value > value1) {
    root->right = addNode(root->right, value1);
  } else {
    root->count++;
  }
  return root;
}
int searchNode(Node* root, const T& value1) {
if (root == nullptr) {
  return 0;
} else if (root->value == value1) {
  return root->count;
} else if (root->value < value1) {
  return searchNode(root->left, value1);
} else {
  return searchNode(root->right, value1);
}
}
int depth_l(Node* root) {
  int Left = 0, Right = 0;
if (root == nullptr) {
  return 0;
} else {
  Left = depth_l(root->left);
  Right = depth_l(root->right);
}
if (Right > Left) {
  return ++Right;
} else {
  return ++Left;
}
}

 public:
  BST() :root(nullptr) {}
  void add(const T& value1) {
    root = addNode(root, value1);
  }
  int search(const T& value1) {
    return searchNode(root, value1);
  }
  int depth() {
    return depth_l(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
