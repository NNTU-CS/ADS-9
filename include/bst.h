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
    Node* right = nullptr;
  };
  Node* root = nullptr;
  Node* addNode(Node* root, T val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->count = 1;
      root->left = root->right = nullptr;
    } else if (val < root->value) {
      root->left = addNode(root->left, val);
    } else if (val > root->value) {
      root->right = addNode(root->right, val);
    } else {
      root->count++;
    }
    return root;
  }
  int searchNode(Node* root, T val) {
    if (root->value == val) {
      return root->count;
    } else if (root->value > val) {
      return searchNode(root->left, val);
    } else {
      return searchNode(root->right, val);
    }
  }
  int depthTree(Node* root) {
    int l = 0;
    int r = 0;
    if (root == nullptr) {
      return 0;
    } else {
      l = depthTree(root->left);
      r = depthTree(root->right);
    }
    return r > l ? (r + 1) : (l + 1);
  }

 public:
  BST() {
    root = nullptr;
  }
  void add(T val) {
    root = addNode(root, val);
  }
  int search(T val) {
    return searchNode(root, val);
  }
  int depth() {
    int a = depthTree(root);
    return a - 1;
  }
};
#endif  // INCLUDE_BST_H_
