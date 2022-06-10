// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
  struct Node {
    Node* leftNode;
    Node* rightNode;
    T value;
    int count;
  };

 private:
  Node* root;
  Node* addNode(Node* root, T value_element) {
    if (root == nullptr) {
      root = new Node;
      root->value = value_element;
      root->count = 1;
      root->leftNode = nullptr;
      root->rightNode = nullptr;
    } else {
      if (value_element > root->value) root->rightNode = addNode(root->rightNode, value_element);
      else if (value_element < root->value) root->leftNode = addNode(root->leftNode, value_element);
      else
       root->count++;
    }
    return root;
  }
  int searchNode(Node* root, T value_element) {
    if (root == nullptr) {
     return 0;
    } else if (root->value == value_element) {
       return root->count;
    } else if (root->value < value_element) {
         return searchNode(root->rightNode, value_element);
    } else {
     return searchNode(root->leftNode, value_element);
    }
  }
  int heightTree(Node* root) {
    if (root == nullptr) {
     return 0;
    } else {
      int left = heightTree(root->leftNode);
      int right = heightTree(root->rightNode);
      if (right > left) {
        return ++right;
      } else {
       return ++left;
      }
    }
}

 public:
  BST() {
    root = nullptr;
  }
  void addNode_(T value_element) {
    root = addNode(root, value_element);
  }
  int search(T value_element) {
    return searchNode(root, value_element);
  }
  int depth() {
  return heightTree(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
