// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <algorithm>

template<typename T>
class BST {
 private:
    struct BSTNode {
        T data;
        int counter;
        BSTNode *left;
        BSTNode *right;
    };
    BSTNode* node;

    BSTNode* insertHelper(BSTNode* node, const T& value) {
        if (node == nullptr) {
            node = new BSTNode;
            node->data = value;
            node->counter = 1;
            node->left = node->right = nullptr;
        } else if (value < node->data) {
            node->left = addNode(node->left, value);
        } else if (value > node->data) {
            node->right = addNode(node->right, value);
        } else {
                node->counter += 1;
        }
    }

    int treeDepthHelper(BSTNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            int leftDepth = treeDepthHelper(node->left);
            int rightDepth = treeDepthHelper(node->right);
            return 1 + std::max(leftDepth, rightDepth);
        }
    }

    BSTNode* searchTreeHelper(BSTNode* node, const T& value) {
        if (node == nullptr || node->data == value) {
            return node;
        } else if (value < node->data) {
            return searchTreeHelper(node->left, value);
        } else {
            return searchTreeHelper(node->right, value);
        }
    }

 public:
    BST() : node(nullptr) {}

    void addNode(const T& value) {
        node = insertHelper(root, value); 
    }

    int depth() {
        return treeDepthHelper(node)-1;
    }

    int search(const T& value) {
        BSTNode* Node = searchTreeHelper(node, value);
        if (Node == nullptr) {
            return 0;
        } else {
            return Node->counter;
        }
    }
};
#endif  // INCLUDE_BST_H_
