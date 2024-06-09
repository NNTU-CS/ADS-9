// Copyright 2021 NNTU-CS
#include <string>
#include <iostream>
#include <algorithm>
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
    struct NODE {
        T value;
        int count;
        NODE *left, *right;
    };
    NODE* root;
    NODE* addNODE(NODE* root, const T& value) {
        if (root == nullptr) {
            root = new NODE;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNODE(root->left, value);
        } else if (root->value < value) {
            root->right = addNODE(root->right, value);
        } else {
            root->count += 1;
        }
        return root;
    }
    int heightTree(NODE* root) {
        if (root == nullptr) return 0;
        return std::max(heightTree(root->left), heightTree(root->right)) + 1;
    }
    NODE* searchTree(NODE* root, const T& value) {
        if (root == nullptr || root->value == value) return root;
        if (value < root->value) return searchTree(root->left, value);
        return searchTree(root->right, value);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = addNODE(root, value); }
    int depth() { return heightTree(root) - 1; }
    int search(const T& value) {
        NODE* current = searchTree(root, value);
        if (current == nullptr) {
            return 0;
        } else {
            return current->count;
        }
    }
};
#endif  // INCLUDE_BST_H_
