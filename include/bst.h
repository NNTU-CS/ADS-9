// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *rt;
    Node *lt;
    int c;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->lt = nullptr;
          root->rt = nullptr;
      } else {
          if (root->val > x) root->lt = addNode(root->lt, x);
          if (root->val < x) root->rt = addNode(root->rt, x);
          if (root->val == x) (root->c)++;
      }
      return root;
    }

  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == x) {
        return root->c;
    } else if (root->val < x) {
        return searchValue(root->rt, x);
    } else {
        return searchValue(root->lt, x);
    }
  }

  int hght(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->lt == nullptr && root->rt == nullptr) return 0;
      int rtt = hght(root->rt), ltt = hght(root->lt);
      if (rtt > ltt)
        return rtt + 1;
      else
        return ltt + 1;
  }

 public:
  BST():root(nullptr) {}
  void add(T x) {
      root = addNode(root, x);
  }
  int depth() {
      return hght(root);
  }
  int search(T x) {
      return searchValue(root, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_

