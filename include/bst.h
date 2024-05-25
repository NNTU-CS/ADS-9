// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>

template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        explicit Node(const T& value) : data(value), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* insert(Node* node, const T& value) {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            node->count++;
        return node;
    }

    int depth(Node* node) const {
        if (!node)
            return 0;
        return 1 + std::max(depth(node->left), depth(node->right));
    }

    int search(Node* node, const T& value) const {
        if (!node)
            return 0;
        if (value < node->data)
            return search(node->left, value);
        if (value > node->data)
            return search(node->right, value);
        return node->count;
    }

 public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    int depth() const {
        return depth(root);
    }

    int search(const T& value) const {
        return search(root, value);
    }
};

#endif  // INCLUDE_BST_H_

