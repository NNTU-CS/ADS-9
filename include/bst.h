// Copyright 2021 NNTU-CS
#include <iostream>
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T> class BST {
 private:
   struct Node {
    Node *left;
    Node *right;
    T data;
    int count;
    Node (const T& data) : data (data), count (1), left(nullptr), right (nullptr) {}
  };

  Node* root;

  void add (Node*& node, const T& data) {
    if (node == nullptr) {
        node = new Node (data);
    } else if (data < node->data) {
        add(node->left, data);
    } else if (data > node->data) {
        add(node->rightm, data);
    } else {
        node->count++;
    }
  }

  void printInOrder (Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data << node->count << std::endl;
        printInOrder(node->right);
    } 
  } 
 public:
  BST() : root (nullptr) {}

  void add (const T& data) {
    add(root, data);
  }

  void printInOrder() {
    printInOrder(root);
  }
};

#endif // INCLUDE_BST_H_
