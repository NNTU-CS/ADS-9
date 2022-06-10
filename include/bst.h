// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T data;
    Node *r;
    Node *l;
    int count;
  };
  Node *root;
  Node *addNode(Node *root, T val) {
      if (root == nullptr) {
          root = new Node;
          root->data = val;
          root->l = nullptr;
          root->r = nullptr;
      } else {
          if (root->data > val) root->l = addNode(root->l, val);
          if (root->data < val) root->r = addNode(root->r, val);
          if (root->data == val) (root->count)++;
      }
      return root;
    }

  int SearchNode(Node* root, T val) {
    if (root == nullptr) {
      return 0;
    } else if (root->data == val) {
        return root->count;
    } else if (root->data < val) {
        return SearchNode(root->r, val);
    } else {
        return SearchNode(root->l, val);
    }
  }

  int TreeHeight(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->l == nullptr && root->r == nullptr) return 0;
      int rt = TreeHeight(root->r), lt = TreeHeight(root->l);
      if (rt > lt)
        return rt + 1;
      else
        return lt + 1;
  }

 public:
  BST():root(nullptr) {}
  void add(T val) {
      root = addNode(root, val);
  }
  int depth() {
      return TreeHeight(root);
  }
  int search(T val) {
      return SearchNode(root, val) + 1;
  }
};

#endif  // INCLUDE_BST_H_
