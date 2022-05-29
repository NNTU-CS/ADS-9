// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    struct Node {
      Node *left;
      int count;
      Node *right;
      T val;
    };

 private:
    Node * root;
    Node * addNode(Node *root, T val) {
      if (root == nullptr) {
        root = new Node;
        root->val = val;
        root->count = 1;
        root->left = root->right = nullptr;
      } else if (root->val > val) {
        root->left = addNode(root->left, val);
      } else if (root->val < val) {
        root->right = addNode(root->right, val);
      } else {
        root->count++;
      }
      return root;
    }
    int depthTree(Node *root) {
      if (root == nullptr) {
        return 0;
      }
      if (root->left == nullptr && root->right == nullptr) {
        return 0;
      }
      int L = depthTree(root->left);
      int R = depthTree(root->right);
      return L > R ? L + 1 : R + 1;
    }
    int searchNode(Node *root, T val) {
      Node *t = root;
      if (root == nullptr) {
        return 0;
      } else {
        if (root->val == val) {
          return root->count;
        } else if (root->val < val) {
          return searchNode(root->right, val);
        } else {
          return searchNode(root->left, val);
        }
      }
    }

 public:
    BST() : root(nullptr) {}
    ~BST() {}
    void add(T val) {
      root = addNode(root, val);
    }
    int depth() {
      return depthTree(root);
    }
    int search(T val) {
      return searchNode(root, val);
    }
};

#endif  // INCLUDE_BST_H_
