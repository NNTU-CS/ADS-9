// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#pragma once
template<typename T>
class BST {
 private:
  struct Node {
  T value;
  int chetchik_num = 0;
  Node* left = nullptr;
  Node* right = nullptr;;
  };
  Node* root;
  Node* addNode(Node* root, const T& val_zn) {
    if (root == nullptr) {
      root = new Node;
      root->value = val_zn;
      root->chetchik_num = 1;
      root->left = root->right = nullptr;
    } else if (root->value < val_zn) {
        root->left = addNode(root->left, val_zn);
      } else if (root->value > val_zn) {
          root->right = addNode(root->right, val_zn);
        } else {
            root->chetchik_num++;
          }
    return root;
    }
    int searchNode(Node* root, const T& val_zn) {
      if (root == nullptr) {
        return 0;
      } else if (root->value == val_zn) {
          return root->chetchik_num;
        } else if (root->value < val_zn) {
            return searchNode(root->left, val_zn);
          } else {
              return searchNode(root->right, val_zn);
            }
    }
    int depth_p(Node* root) {
      int x = 0, xx = 0;
      if (root == nullptr) {
        return 0;
      } else {
          x = depth_p(root->left);
          xx = depth_p(root->right);
        }
        if (xx > x) {
            return ++xx;
        } else {
            return ++x;
          }
    }

 public:
  BST() :root(nullptr) {}
  void Add(const T& val_zn) {
    root = addNode(root, val_zn);
  }
  int search(const T& val_zn) {
    return searchNode(root, val_zn);
  }
  int depth() {
    return depth_p(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
