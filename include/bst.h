// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>

template <typename T>
class BST {
 private:
  struct Node {
    T data;
    int count;
    Node* left;
    Node* right;
  };
  Node<T>* root;
  void insert(Node<T>*& node, const T& value);
  void displayInOrder(Node<T>* node) const;
};

 public:
  BST();
  void insert(const T& value);
  void displayInOrder() const;
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
void BST<T>::insert(const T& value) {
  insert(root, value);
}

template <typename T>
void BST<T>::insert(Node<T>*& node, const T& value) {
  if (node == nullptr) {
    node = new Node<T>{value, 1, nullptr, nullptr};
  } else if (value < node->data) {
    insert(node->left, value);
  } else if (value > node->data) {
    insert(node->right, value);
  } else {
    node->count++;
  }
}

template <typename T>
void BST<T>::displayInOrder() const {
  displayInOrder(root);
}

template <typename T>
void BST<T>::displayInOrder(Node<T>* node) const {
  if (node != nullptr) {
    displayInOrder(node->left);
    std::cout << node->data << " : " << node->count << std::endl;
    displayInOrder(node->right);
  }
}
#endif  // INCLUDE_BST_H_
