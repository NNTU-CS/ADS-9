// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

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
  Node* addNode(Node* node, T value) {
    if (!node) {
      node = new Node;
      node->value = value;
      node->count = 1;
      node->left = node->right = nullptr;
    } else if (node->value > value) {
      node->left = addNode(node->left, value);
    } else if (node->value < value) {
      node->right = addNode(node->right, value);
    } else {
      node->count++;
    }
    return node;
  }
  int searchValue(Node* node, T value) {
    if (!node) {
      return 0;
    } else if (node->value == value) {
      return node->count;
    } else if (node->value > value) {
      return searchValue(node->left, value);
    } else {
      return searchValue(node->right, value);
    }
  }
  int heightTree(Node* node) {
    if (!node) {
      return 0;
    }
    int leftHeight = heightTree(node->left);
    int rightHeight = heightTree(node->right);
    return std::max(leftHeight, rightHeight) + 1;
  }

 public:
  BST() : root(nullptr) {}

  void add(T value) {
    root = addNode(root, value);
  }
  int search(T value) {
    return searchValue(root, value);
  }
  int depth() {
    return heightTree(root) - 1;
  }
};

#endif  // INCLUDE_BST_H_
