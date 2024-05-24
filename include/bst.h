// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include "bst.h"
#include <algorithm>
#include <string>

template <typename T>
struct Node {
  T data;
  Node* left;
  Node* right;
  int count;

  explicit Node(T value)
      : data(value), left(nullptr), right(nullptr), count(1) {}
};

template <typename T>
class BST {
 private:
  Node<T>* root;

  int Height(Node<T>* node) {
    if (node == nullptr) return 0;
    int Height_left = Height(node->left);
    int Height_right = Height(node->right);
    return std::max(Height_left, Height_right) + 1;
  }

  Node<T>* insert(Node<T>* node, T value) {
    if (node == nullptr) {
      node = new Node<T>(value);
    } else if (node->data > value) {
      node->left = insert(node->left, value);
    } else if (node->data < value) {
      node->right = insert(node->right, value);
    } else {
      node->count++;
    }
    return node;
  }

  int findVal(Node<T>* node, T value) {
    if (node->data == value)
      return node->count;
    else if (node->data > value)
      return findVal(node->left, value);
    else if (node->data < value)
      return findVal(node->right, value);
    else
      return 0;
  }

  void deleteTree(Node<T>* node) {
    if (node == nullptr) return;
    deleteTree(node->right);
    deleteTree(node->left);
    delete node;
    node = nullptr;
  }

 public:
  BST() : root(nullptr) {}

  void insert(T value) { root = insert(root, value); }

  int depth() { return Height(root) - 1; }

  int search(T value) { return findVal(root, value); }

  ~BST() { deleteTree(root); }
};

#endif  // INCLUDE_BST_H_
