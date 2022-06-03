// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T vl;
    int ch;
    Node *h;
    Node *k;
  };
  Node root;
  Node addNode(Node root, T nz) {
    if (!root) {
      root = new Node;
      root->vl = nz;
      root->h = root->r = nullptr;
    } else if (root->vl > nz) {
      root->h = addNode(root->h, nz);
    } else if (root->vl < nz) {
      root->k = addNode(root->k, nz);
    } else {
      (root->ch)++;
    }
    return root;
  }
  int srchValue(Node root, T nz) {
    if (!root) {
      return 0;
    } else if (root->vl == nz) {
      return root->ch;
    } else if (root->vl > nz) {
      return srchValue(root->l, nz);
    } else {
      return srchValue(root->k, nz);
    }
  }
  int hghtTree(Node* root) {
    if (!root) {
      return 0;
    }
    int H = hghtTree(root->h);
    int R = hghtTree(root->k);
    if (H > R) {
      return (H + 1);
    } else {
      return (R + 1);
    }
  }
   public:
  BST() :root(nullptr) {}
  void add(T nz) {
    root = addNode(root, nz);
  }
  int srch(T nz) {
    return srchValue(root, nz) + 1;
  }
  int glub() {
    return hghtTree(root) - 1;
  }
};

#endif  // INCLUDE_BST_H_
