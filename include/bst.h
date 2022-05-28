// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
template <typename T>
class BST {
 private:
  struct Node {
    int count;
    T value;
    Node* right;
    Node* left;
  };
  Node* root;

  int heightTree(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int R = heightTree(root->right);
    int L = heightTree(root->left);
    if (L > R) {
      return (L+1);
    } else {
      return (R+1);
    }
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

  void printTree(Node* root) {
    if (root == nullptr) {
      return;
    } else {
      printTree(root->left);
      for (int i = 0; i < root->count; i++) {
        std::cout << root->value << " ";
        std::cout << '\n';
        printTree(root->right);
      }
    }
  }

  int searchNode(Node* root, T val) {
    if (root == nullptr) {
      return 0;
    } else if (root->value == val) {
      return root->count;
    } else if (root-> value > val) {
      return searchNode(root->left, val);
    } else {
      return searchNode(root->right, val);
    }
  }

  Node* addNode(Node* root, T val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->count = 1;
      root->right = root->left = nullptr;
    } else if (val < root->value) {
      root->left = addNode(root->left, val);
    } else if (val > root->value) {
      root->right = addNode(root->right, val);
    } else {
      root->count++;
    }
    return root;
  }

 public:
  BST(): root(nullptr) {}

  void add(T val) {
    root = addNode(root, val);
  }

  int depth() {
    return heightTree(root) - 1;
  }

  int search(T val) {
    return searchNode(root, val);
  }
};
#endif  // INCLUDE_BST_H_
