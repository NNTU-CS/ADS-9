// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class BST {
 public:
    struct TreeNode {
        T value;
        int count;
        TreeNode* left;
        TreeNode* right;
    };

 private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, T value) {
        if (node == nullptr) {
            node = new TreeNode;
            node->value = value;
            node->count = 1;
            node->left = node->right = nullptr;
        } else if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            node->count++;
        }
        return node;
    }

    int calculateDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            int leftDepth = calculateDepth(node->left);
            int rightDepth = calculateDepth(node->right);
            return std::max(leftDepth, rightDepth) + 1;
        }
    }

    int find(TreeNode* node, T value) {
        if (node == nullptr) {
            return 0;
        } else if (value == node->value) {
            return node->count;
        } else if (value < node->value) {
            return find(node->left, value);
        } else {
            return find(node->right, value);
        }
    }

 public:
    BST() : root(nullptr) {}

    void add(T value) {
        root = insert(root, value);
    }

    int depth() {
        return calculateDepth(root) - 1;
    }

    int search(T value) {
        return find(root, value);
    }
};

#endif  // INCLUDE_BST_H_
