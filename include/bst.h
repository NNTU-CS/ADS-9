// Copyright 2022 Matvey Ryabchikov
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count = 0;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  Node* root;
  Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->count = 1;
      root->left = root->right = nullptr;
    } else if (root->value < val) {
      root->left = addNode(root->left, val);
    } else if (root->value > val) {
      root->right = addNode(root->right, val);
    } else {
      root->count++;
    }
    return root;
  }
  int searchNode(Node* root, const T& val) {
    return root == nullptr ? 0
           : root->value == val
               ? root->count
               : searchNode(root->value < val ? root->left : root->right, val);
  }
  int depth_p(Node* root) {
    if (root == nullptr) return 0;
    int left = depth_p(root->left), right = depth_p(root->right);
    return ++(right > left ? right : left);
  }

 public:
  BST() : root(nullptr) {}
  void add(const T& val) { root = addNode(root, val); }
  int search(const T& val) { return searchNode(root, val); }
  int depth() { return depth_p(root) - 1; }
};

#endif  // INCLUDE_BST_H_
