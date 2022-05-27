// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int coun = 0;
    Node* lroot = nullptr;
    Node* rroot = nullptr;
  };
  Node* root;
  Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->coun = 1;
      root->lroot = root->rroot = nullptr;
    } else if (root->value < val) {
      root->lroot = addNode(root->lroot, val);
    } else if (root->value > val) {
      root->rroot = addNode(root->rroot, val);
    } else {
      root->coun++;
    }
      return root;
  }
  int depth_p(Node* root) {
    int lcoun = 0, rcoun = 0;
    if (root == nullptr) {
      return 0;
    } else {
      lcoun = depth_p(root->lroot);
      rcoun = depth_p(root->rroot);
    }
    if (rcoun > lcoun) {
      return ++rcoun;
    } else {
      return ++lcoun;
    }
  }
  int searchNode(Node* root, const T& val) {
    if (root == nullptr) {
      return 0;
    } else if (root->value == val) {
      return root->coun;
    } else if (root->value < val) {
      return searchNode(root->lroot, val);
    } else {
      return searchNode(root->rroot, val);
    }
  }

 public:
  BST() :root(nullptr) {}
  void AddNode(const T& val) {
    root = addNode(root, val);
  }
  int depth() {
    return depth_p(root)-1;
  }
  int search(const T& val) {
    return searchNode(root, val);
  }
};
#endif  // INCLUDE_BST_H_
