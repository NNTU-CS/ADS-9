// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
  T value;
  int count = 0;
  Node* left = nullptr;
  Node* right = nullptr;;
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
      if (root == nullptr) {
        return 0;
      } else if (root->value == val) {
          return root->count;
        } else if (root->value < val) {
            return searchNode(root->left, val);
          } else {
              return searchNode(root->right, val);
            }
    }
    int depth_p(Node* root) {
      int lft = 0, rht = 0;
      if (root == nullptr) {
        return 0;
      } else {
          lft = depth_p(root->left);
          rht = depth_p(root->right);
        }
        if (rht > lft) {
            return ++rht;
        } else {
            return ++lft;
          }
    }

 public:
  BST() :root(nullptr) {}
  void Add(const T& val) {
    root = addNode(root, val);
  }
  int search(const T& val) {
    return searchNode(root, val);
  }
  int depth() {
    return depth_p(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
