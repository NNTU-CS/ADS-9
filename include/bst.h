// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    Node* left;
    Node* right;
    int count;
  };
  Node* root;
  Node* addNode(Node* node, T value) {
    if (node == nullptr) {
      node = new Node;
      node->value = value;
      node->left = nullptr;
      node->right = nullptr;
      node->count = 1;
    } else if (node->value > value) {
      node->left = addNode(node->left, value);
    } else if (node->value < value) {
      node->right = addNode(node->right, value);
    } else {
      node->count += 1;
    }
    return node;
  }
  int depthTree(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = depthTree(node->left);
    int right = depthTree(node->right);
    if (left >= right) {
      return left + 1;
    } else {
      return right + 1;
    }
  }
  int searchTree(Node* node, T value) {
    if (node == nullptr) {
      return 0;
    } else if (node->value < value) {
      return searchTree(node->right, value);
    } else if (node->value > value) {
      return searchTree(node->left, value);
    }
    return node->count;
  }

 public:
  BST() {
    root = nullptr;
  }
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return depthTree(root) - 1;
  }
  int search(T value) {
    return searchTree(root, value);
  }
};

#endif  // INCLUDE_BST_H_
