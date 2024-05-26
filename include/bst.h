// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <iostream>

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
        int result = search(root, value);
        std::cout << "Search result for " << value << ": " << result << std::endl;
        return result;
    }

    int depth() const {
        int d = depth(root);
        std::cout << "Tree depth: " << d << std::endl;
        return d;
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
            std::cout << "Node not found: " << value << std::endl;
            return 0;
        }
        if (value == node->value) {
            std::cout << "Node found: " << value << std::endl;
            return 1;
        } else if (value < node->value) {
            std::cout << "Searching left for: " << value << std::endl;
            return search(node->left, value);
        } else {
            std::cout << "Searching right for: " << value << std::endl;
            return search(node->right, value);
        }
    }

    int depth(Node* node) const {
        if (!node) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        int d = std::max(leftDepth, rightDepth) + 1;
        std::cout << "Current depth at node " << node->value << ": " << d << std::endl;
        return d;
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
