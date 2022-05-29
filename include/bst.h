// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename t>
struct node {
    node<t>* right = nullptr;
    node<t>* left = nullptr;
    node<t>* prev = nullptr;
    int count = 0;
    t value = "";
};
template <typename t>
class BST {
  private:
  node<t>* root = nullptr;
  int height = 0;
  
  public:
  BST() {
    root = nullptr;
    height = 0;
  }
  ~BST() {
    delnode(root);
  }
  void add(t item) {
    node<t>* cur = root;
    node<t>* prev = nullptr;
    int pos = 0;
    while (true) {
      if (cur == nullptr) {
        cur = new node<t>;
        cur->left = nullptr;
        cur->right = nullptr;
        cur->value = item;
        cur->count = 1;
        if (prev != nullptr) {
          cur->prev = prev;
          if (pos == 1) {
            prev->right = cur;
          } else {
            prev->left = cur;
          }
          pos = 0;
          prev = nullptr;
        }
        if (root == nullptr) {
          root = cur;
        }
        break;
      }
      if (cur->value < item) {
        prev = cur;
        pos = 1;
        cur = cur->right;
      } else if (cur->value == item) {
        cur->count++;
        break;
      } else {
        prev = cur;
        pos = -1;
        cur = cur->left;
      }
    }
  }
};
#endif  // INCLUDE_BST_H_
