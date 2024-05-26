// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename T>
struct BSTNode {
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = insertRecursive(root, value);
    }

    bool contains(const T& value) const {
        return containsRecursive(root, value);
    }

    int count(const T& value) const {
        BSTNode<T>* node = findNode(root, value);
        return node ? node->count : 0;
    }

private:
    BSTNode<T>* root;

    BSTNode<T>* insertRecursive(BSTNode<T>* node, const T& value) {
        if (!node) {
            return new BSTNode<T>(value);
        }

        if (value < node->value) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = insertRecursive(node->right, value);
        } else {
            node->count++;
        }

        return node;
    }

    bool containsRecursive(BSTNode<T>* node, const T& value) const {
        if (!node) {
            return false;
        }

        if (value == node->value) {
            return true;
        }

        if (value < node->value) {
            return containsRecursive(node->left, value);
        } else {
            return containsRecursive(node->right, value);
        }
    }

    BSTNode<T>* findNode(BSTNode<T>* node, const T& value) const {
        if (!node || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return findNode(node->left, value);
        } else {
            return findNode(node->right, value);
        }
    }
};
#endif  // INCLUDE_BST_H_
