// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node *left;
    Node *right;
  };

 private:
  Node *root;
  Node *addNode(Node *root, T num) {
    if (root == nullptr) {
      root = new Node;
      root->left = nullptr;
      root->right = nullptr;
      root->value = num;
    } else if (root->value < num) {
        root->right = addNode(root->right, num);
    } else if (root->value > num) {
        root->left = addNode(root->left, num);
    } else {
      ++(root->count);
    }
    return root;
  }
  int depth(Node *root) {
    if (root == nullptr)
      return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    if (leftDepth > rightDepth) {
      return (leftDepth + 1);
    } else {
      return (rightDepth + 1);
    }
  }
  int seek(Node *root, T num) {
    if (root != nullptr) {
      if (root->value == num) {
        return root->count;
      } else if (root->value < num) {
        return seek(root->right, num);
      } else {
        return seek(root->left, num);
      }
    } else {
      return 0;
    }
  }

 public:
  BST() : root(nullptr) {}
  void add(T num) {
    root = addNode(root, num);
  }
  int depth() {
    return depth(root) - 1;
  }
  int search(T num) {
    return seek(root, num) + 1;
  }
};
#endif  // INCLUDE_BST_H_
