// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BST() : root(nullptr) {}

    bool insert(const T& val) {
        return insertRecursive(root, val);
    }

    bool contains(const T& val) const {
        return containsRecursive(root, val);
    }

    int count() const {
        return countRecursive(root);
    }

private:
    bool insertRecursive(Node*& node, const T& val) {
        if (!node) {
            node = new Node(val);
            return true;
        }

        if (val < node->data) {
            return insertRecursive(node->left, val);
        } else if (val > node->data) {
            return insertRecursive(node->right, val);
        } else {
            return false;
        }
    }

    bool containsRecursive(Node* node, const T& val) const {
        if (!node) {
            return false;
        }

        if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return containsRecursive(node->left, val);
        } else {
            return containsRecursive(node->right, val);
        }
    }

    int countRecursive(Node* node) const {
        if (!node) {
            return 0;
        }
        return 1 + countRecursive(node->left) + countRecursive(node->right);
    }
};
#endif  // INCLUDE_BST_H_
