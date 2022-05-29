// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *r;
    Node *l;
    int count;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->l = nullptr;
          root->r = nullptr;
      } else {
          if (root->val > x) root->l = addNode(root->l, x);
          if (root->val < x) root->r = addNode(root->r, x);
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
        return searchValue(root->r, x);
    } else {
        return searchValue(root->l, x);
    }
  }

  int ht(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->l == nullptr && root->r == nullptr) return 0;
      int rt = ht(root->r), lt = ht(root->l);
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
      return ht(root);
  }
  int search(T x) {
      return searchValue(root, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_
