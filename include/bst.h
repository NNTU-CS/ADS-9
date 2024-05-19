// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;
  Node* addNode(Node*, T);
  int searchTree(Node*, T, int&);
  int depthTree(Node*);
 public:
  BST();
  void add(T);
  int search(T);
  int depth();
};

template <typename T>
BST<T>::BST() {
  root = nullptr;
}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addNode(root->left, value);
  } else if (root->value < value) {
    root->right = addNode(root->right, value);
  } else {
    root->count++;
  }
  return root;
}

template <typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}

template <typename T>
int BST<T>::searchTree(Node* root, T value, int& maxCount) {
  if (root == nullptr) {
    return 0;
  } else if (value < root->value) {
    return searchTree(root->left, value, maxCount);
  } else if (value > root->value) {
    return searchTree(root->right, value, maxCount);
  } else {
    if (root->count > maxCount) {
      maxCount = root->count;
    }
    return root->count;
  }
}

template <typename T>
int BST<T>::search(T value) {
  int maxCount = 0;
  return searchTree(root, value, maxCount);
}

template <typename T>
int BST<T>::depthTree(Node* root) {
  if (root == nullptr)
    return 0;
  int hL = depthTree(root->left);
  int hR = depthTree(root->right);
  if (hL > hR) {
    return hL + 1;
  } else {
    return hR + 1;
  }
}

template <typename T>
int BST<T>::depth() {
  return depthTree(root) - 1;
}

#endif  // INCLUDE_BST_H_
