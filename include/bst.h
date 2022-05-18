// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *right;
    Node *left;
    int count;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->left = nullptr;
          root->right = nullptr;
      } else {
          if (root->val > x) root->left = addNode(root->left, x);
          if (root->val < x) root->right = addNode(root->right, x);
          if (root->val == x) (root->count)++;
      }
      return root;
    }

  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == x) {
        return root->count;
    } else if (root->val < x) {
        return searchValue(root->right, x);
    } else {
        return searchValue(root->left, x);
    }
  }

  int height(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->left == nullptr && root->right == nullptr) return 0;
      int rt = height(root->right), lt = height(root->left);
      if (rt > lt)
        return rt + 1;
      else
        return lt + 1;
  }

 public:
  BST():root(nullptr) {}
  void add(T x) {
      root = addNode(root, x);
  }
  int depth() {
      return height(root);
  }
  int search(T x) {
      return searchValue(root, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_
