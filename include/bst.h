// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node * left;
    Node * right;
  };

 private:
  Node * root;
  Node * addNode(Node *root, T value) {
    if (nullptr == root) {
      root = new Node;
      root->left = root->right = nullptr;
      root->value = value;
      root->count = 1;
    } else if (root->value < value) {
      root->right = addNode(root->right, value);
    } else if (root->value > value) {
      root->left = addNode(root->left, value);
    } else {
      root->count++;
    }
    return root;
  }
  int searchNode(Node *root, T value) {
    if (nullptr == root) {
      return 0;
    } else {
      if (root->value == value) {
        return root->count;
      } else if (root->value > value) {
               return searchNode(root->left, value);
             } else {
               return searchNode(root->right, value);
               }
      }
  }
  int depthTree(Node *root) {
    int leftt, rightt;
    if (nullptr == root)
      return 0;
    if (nullptr == root->left && nullptr == root->right)
      return 0;
    leftt = depthTree(root->left);
    rightt = depthTree(root->right);
    return (leftt > rightt) ? (++leftt) : (++rightt);
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
    return depthTree(root);
  }
};
#endif  // INCLUDE_BST_H_
