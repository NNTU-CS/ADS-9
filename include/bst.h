// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

using namespace std;

template<typename T>

class BST {
private:
  struct Node {
    T value;
    Node* left, * right;
    int k;
  };

  Node* root;
  int addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->k = 1;
      root->left = root->right = nullptr;
    }
    else if (root->value > value)
    {
      root->left = addNode(root->left, value);
    }
    else if (root->value < value) {
      root->right = addNode(root->right, value);
    }
    else {
      root->k++;
    }
    return root;
  }
  int Depth(Node* root) {
    int hl, hr;
    if (root == nullptr) {
      return 0;
    }
    hl = Depth(root->left);
    hr = Depth(root->right);
    return max(hl, hr) + 1;
  }
  int Search(Node* root, T value) {
    if (root == nullptr) {
      return 0;
    }
    else if (value < root->value) {
      return Search(root->left, value);
    }
    else if (value > root->value) {
      return Search(root->right, value);
    }
    else return root->k;
  }
  void Del(Node* root) {
    if (root == nullptr)
      return;
    Del(root->left);
    Del(root->right);
    delete root;
    root = nullptr;
  }
public:
  BST() : root(nullptr) {}
  void addNew(T value) {
    root = addNode(root, value);
  }

  int depth() {
    return Depth(root) - 1;
  }

  int search(T value) {
    return Search(root, value);
  }

  ~BST() {
      Del(root);
  }
};

#endif  // INCLUDE_BST_H_
