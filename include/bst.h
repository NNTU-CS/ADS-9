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
  Node *root;
  Node* addNode(Node *root, T nz) {
    if (!root) {
      root = new Node;
      root->vl = nz;
      root->h = root->k = nullptr;
    } else if (root->vl > nz) {
      root->h = addNode(root->h, nz);
    } else if (root->vl < nz) {
      root->k = addNode(root->k, nz);
    } else {
      (root->ch)++;
    }
    return root;
  }
  int searchValue(Node* root, T nz) {
    if (!root) {
      return 0;
    } else if (root->vl == nz) {
      return root->ch;
    } else if (root->vl > nz) {
      return searchValue(root->h, nz);
    } else {
      return searchValue(root->k, nz);
    }
  }
  int heightTree(Node* root) {
    if (!root) {
      return 0;
    }
    int K = heightTree(root->k);
    int H = heightTree(root->h);
    if (H > K) {
      return (H + 1);
    } else {
      return (K + 1);
    }
  }

 public:
  BST() :root(nullptr) {}
  void add(T nz) {
    root = addNode(root, nz);
  }
  int search(T nz) {
    return searchValue(root, nz) + 1;
  }
  int depth() {
    return heightTree(root) - 1;
  }
};

#endif  // INCLUDE_BST_H_
