// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left, * right;
  };
  Node* root;

  Node* addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->left = root->right = nullptr;
    } else if (root->value < value) {
      root->left = addNode(root->left, value);
    } else if (root->value > value) {
      root->right = addNode(root->right, value);
    } else {
      root->count++;
    }
      return root;
  }

  int searchNode(Node* root, T value) {
    if (root == nullptr)
      return 0;
    else if (root->value < value)
      return searchNode(root->left, value);
    else if (root->value > value)
      return searchNode(root->right, value);
    else
      return root->count;
  }

  int heightTree(Node* root) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 0;
    int l = heightTree(root->left);
    int r = heightTree(root->right);
    return r > l ? r + 1 : l + 1;
  }

 public:
  BST() : root(nullptr) {}
  ~BST() {}

  void add(T value) {
    root = addNode(root, value);
  }
  int search(T value) {
    return searchNode(root, value);
  }
  int depth() {
    return heightTree(root);
  }
};

#endif  // INCLUDE_BST_H_
