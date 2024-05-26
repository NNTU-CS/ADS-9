// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
template < typename T >
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
    explicit Node(T value) : value(value), count(1), left(nullptr), right(nullptr) {}
  };

 private:
    Node* root;
    Node* insertNode(Node* root, T value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->value) {
            root->left = insertNode(root->left, value);
        } else if (value > root->value) {
            root->right = insertNode(root->right, value);
        } else {
            root->count++;
        }
        return root;
    }
    Node* searchNode(Node* root, T value) {
        if (root == nullptr || root->value == value) {
            return root;
        }
        if (value < root->value) {
            return searchNode(root->left, value);
        } else {
            return searchNode(root->right, value);
        }
    }
    int getDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int leftDepth = getDepth(root->left);
            int rightDepth = getDepth(root->right);
            return std::max(leftDepth, rightDepth) + 1;
        }
    }

 public:
    BST() : root(nullptr) {}
    void add(T value) {
        root = insertNode(root, value);
    }
    int depth() {
        return getDepth(root) - 1;
    }
    int search(T value) {
        Node* node = searchNode(root, value);
        return (node != nullptr) ? node->count : 0;
    }
};
#endif  // INCLUDE_BST_H_
