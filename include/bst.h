// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
  struct NODE {
    T value;
    int count;
    NODE* left;
    NODE* right;
  };
  NODE* root = nullptr;

  NODE* AddNode(NODE* root, const T& value) {
    if (root == nullptr) {
      root = new NODE;
      root->value = value;
      root->count = 1;
      root->left = nullptr;
      root->right = nullptr;
    } else if (root->value > value) {
      root->left = AddNode(root->left, value);
    } else if (root->value < value) {
      root->right = AddNode(root->right, value);
    } else {
      root->count += 1;
    }
    return root;
  }

  NODE* SearchTree(NODE* root, const T& value) {
    if (root->value == value) {
      return root;
    } else if (root == nullptr) {
      return root;
    }
    if (root->value < value) {
      return SearchTree(root->left, value);
    } else {
      return SearchTree(root->right, value);
    }
  }

  int DepthTree(NODE* root) {
    if (!root) {
      return 0;
    } else {
      return std::max(DepthTree(root->left), DepthTree(root->right))+1;
    }
  }

 public:
  BST() {};

  void add(const T& value) {
    root = AddNode(root, value); 
  }
  
  int search(const T& value) {
    NODE* current = SearchTree(root, value);
    if (current == nullptr) {
      return 0;
    } else {
      return current->count;
    }
  }
  int depth() {
    return DepthTree(root) - 1;
  }

  char LowercaseTranslation(char Token) {
    if (Token >= 'A' && Token <= 'Z') {
      Token = Token + ('a' - 'A');
    }
    return Token;
  }
};

#endif  // INCLUDE_BST_H_
