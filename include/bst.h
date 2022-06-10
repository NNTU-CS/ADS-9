// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node * left, * right;
  };
  Node * root;
  int searchNode(Node * root, T value1) {
    if (root == nullptr)
      return 0;
    else if (root -> value == value1)
      return root -> count;
    else if (root -> value > value1)
      return searchNode(root -> left, value1);
    else
      return searchNode(root -> right, value1);
  }
  Node * addNode(Node * root, T value1) {
    if (root == nullptr) {
      root = new Node;
      root -> value = value1;
      root -> count = 1;
      root -> left = root -> right = nullptr;
    } else if (value1 < root->value) {
      root->left = addNode(root->left, value1);
    } else if (value1 > root->value) {
      root->right = addNode(root->right, value1);
    } else {
      root->count++;
    }
      return root;
  }
  int heightTree(Node * root) {
      int l, r, h = 0;
    if (root != nullptr) {
        l = heightTree(root->left);
        r = heightTree(root->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
  }

 public:
  BST() :root(nullptr) {}
  int search(T value) {
    return searchNode(root, value);
  }
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return heightTree(root) - 1;
  }
};

#endif  // INCLUDE_BST_H_
