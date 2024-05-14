// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#pragma once
#include <string>
template <typename T>
struct Node {
    T data;
    int count;
    Node* left;
    Node* right;

    Node(const T& d) : data(d), count(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    Node<T>* root;

    void insert(Node<T>*& node, const T& value) {
        if (!node) {
            node = new Node<T>(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        } else {
            node->count++;
        }
    }

    int getCount(Node<T>* node, const T& value) const {
        if (!node) {
            return 0;
        }
        if (value == node->data) {
            return node->count;
        } else if (value < node->data) {
            return getCount(node->left, value);
        } else {
            return getCount(node->right, value);
        }
    }

    int depth(Node<T>* node) const {
        if (!node) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    int search(Node<T>* node, const T& value, int depth) const {
        if (!node) {
            return -1;
        }
        if (node->data == value) {
            return depth;
        }
        int leftDepth = search(node->left, value, depth + 1);
        if (leftDepth != -1) {
            return leftDepth;
        }
        return search(node->right, value, depth + 1);
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        insert(root, value);
    }

    int getCount(const T& value) const {
        return getCount(root, value);
    }

    int depth() const {
        return depth(root);
    }

    int search(const T& value) const {
        return search(root, value, 0);
    }
};
#endif  // INCLUDE_BST_H_
