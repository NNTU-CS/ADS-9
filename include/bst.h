// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>

template <typename T>
class BST {
 private:
  struct Node {
    T data;
    int count;
    Node* left;
    Node* right;

    Node(const T& d) : data(d), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

 public:
  BST() : root(nullptr) {}

  void insert(const T& word) {
    root = insertRecursive(root, word);
  }

  int getCount(const T& word) const {
    Node* node = findNode(root, word);
    return node ? node->count : 0;
  }

 private:
  Node* insertRecursive(Node* node, const T& word) {
    if (!node) {
      return new Node(word);
    }

    if (word < node->data) {
      node->left = insertRecursive(node->left, word);
    } else if (word > node->data) {
      node->right = insertRecursive(node->right, word);
    } else {
      node->count++;
    }

    return node;
  }

  Node* findNode(Node* node, const T& word) const {
    if (!node) {
      return nullptr;
    }

    if (word < node->data) {
      return findNode(node->left, word);
    } else if (word > node->data) {
      return findNode(node->right, word);
    } else {
      return node;
    }
  }
};

#endif  // INCLUDE_BST_H_
