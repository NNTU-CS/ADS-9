// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
class BST {
 public:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        explicit Node(T val) : data(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const T& value) {
        root = insertRec(root, value);
    }

    int depth() const {
        return depth(root);
    }

    Node* search(const T& val) const {
        return search(root, val);
    }

    int getDepth(const T& val) const {
        return getDepthRec(root, val);
    }

 private:
     int depth(Node* node) const {
        if (!node) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    Node* search(Node* node, const T& val) const {
        if (!node || node->data == val) {
            return node;
        }
        if (val < node->data) {
            return search(node->left, val);
        }
        return search(node->right, val);
    }

    Node* insertRec(Node* node, const T& value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else {
            node->count++;
        }
        return node;
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    int getDepthRec(Node* node, const T& val, int depth = 0) const {
        if (!node) {
            return -1;
        }
        if (node->data == val) {
            return depth;
        }
        if (val < node->data) {
            return getDepthRec(node->left, val, depth + 1);
        }
        return getDepthRec(node->right, val, depth + 1);
    }
};

#endif  // INCLUDE_BST_H_
