// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node *left;
    Node *right;
  };
  Node *root;
  Node* addNode(Node *root, T v) {
    if (!root) {
      root = new Node;
      root->value = v;
      root->left = root->right = nullptr;
    } else if (root->value > v) {
      root->left = addNode(root->left, v);
    } else if (root->value < v) {
      root->right = addNode(root->right, v);
    } else {
      (root->count)++;
    }
    return root;
  }
  int heightTree(Node* root) {
    if (!root) {
      return 0;
    }
    int Left = heightTree(root->left);
    int Right = heightTree(root->right);
    if (Left > Right) {
      return (Left + 1);
    } else {
      return (Right + 1);
    }
  }
  int searchValue(Node* root, T v) {
    if (!root) {
      return 0;
    } else if (root->value == v) {
      return root->count;
    } else if (root->value > v) {
      return searchValue(root->left, v);
    } else {
      return searchValue(root->right, v);
    }
  }

 public:
    BST() :root(nullptr) {}
    void add(T v) {
      root = addNode(root, v);
    }
    int search(T v) {
      return searchValue(root, v) + 1;
    }
    int depth() {
      return heightTree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
