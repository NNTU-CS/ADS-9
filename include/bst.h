// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *rght;
    Node *lft;
    int ct;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->lft = nullptr;
          root->rght = nullptr;
      } else {
          if (root->val > x) root->lft = addNode(root->lft, x);
          if (root->val < x) root->rght = addNode(root->rght, x);
          if (root->val == x) (root->ct)++;
      }
      return root;
    }

  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == x) {
        return root->ct;
    } else if (root->val < x) {
        return searchValue(root->rght, x);
    } else {
        return searchValue(root->lft, x);
    }
  }

  int height(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->lft == nullptr && root->rght == nullptr) return 0;
      int rrt = height(root->rght), llt = height(root->lft);
      if (rrt > llt)
        return rrt + 1;
      else
        return llt + 1;
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
