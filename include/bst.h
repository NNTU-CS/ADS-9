// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
class BST {
 public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& value) {
        std::cout << "Inserting: " << value << std::endl;
        root = insert(root, value);
    }

    int search(const T& value) const {
        std::cout << "Searching for: " << value << std::endl;
        return search(root, value);
    }

    int depth() const {
        std::cout << "Calculating depth" << std::endl;
        return depth(root);
    }

 private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        explicit Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& value) {
        if (!node) {
            std::cout << "Creating new node for: " << value << std::endl;
            return new Node(value);
        }
        if (value < node->value) {
            std::cout << "Going left: " << value << std::endl;
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            std::cout << "Going right: " << value << std::endl;
            node->right = insert(node->right, value);
        }
        return node;
    }

    int search(Node* node, const T& value) const {
        if (!node) {
            return 0;
        }
        if (value == node->value) {
            return 1;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    int depth(Node* node) const {
        if (!node) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

#endif  // INCLUDE_BST_H_
