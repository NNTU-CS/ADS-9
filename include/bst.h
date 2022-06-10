// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T value;
    Node *rght;
    Node *lft;
    int count;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->value = x;
          root->lft = nullptr;
          root->rght = nullptr;
      } else {
          if (root->value > x) root->lft = addNode(root->lft, x);
          if (root->value < x) root->rght = addNode(root->rght, x);
          if (root->value == x) (root->count)++;
      }
      return root;
    }

  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->value == x) {
        return root->count;
    } else if (root->value < x) {
        return searchValue(root->rght, x);
    } else {
        return searchValue(root->lft, x);
    }
  }

  int height(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->lft == nullptr && root->rght == nullptr) return 0;
      int rt = height(root->rght), lt = height(root->lft);
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
