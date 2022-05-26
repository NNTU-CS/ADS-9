// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>

class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left, * right;
  };
  Node* root;

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
    if (root == nullptr) {
      return 0;
    } else if (root->value == val) {
      return root->count;
    } else if (root->value > val) {
      return searchNode(root->left, val);
    } else {
      return searchNode(root->right, val);
    }
  }

  int heightTree(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int L = heightTree(root->left);
    int R = heightTree(root->right);
    return ((L > R) ? L : R)+1;
  }

  void delTree(Node* root) {
     if (root == nullptr) {
       return;
     } else {
       delTree(root->left);
       delTree(root->right);
       delete root;
     }
  }

 public:
  BST(): root(nullptr) {}

  void add(T val) {
    root = addNode(root, val);
  }

  int search(T val) {
    return searchNode(root, val);
  }

  int depth() {
    return heightTree(root)-1;
  }
};
#endif  // INCLUDE_BST_H_
