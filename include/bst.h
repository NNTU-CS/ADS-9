// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template<typename T>
class BST {
private:
    struct Node {
        T value;
        Node *left;
        Node *right;
        int count;
        explicit Node(T v) {
            left = nullptr;
            right = nullptr;
            count = 1;
            value = v;
        }
    };
    Node *root;

    Node *addNode(Node *node, const T &value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = addNode(node->left, value);
        } else if (value > node->value) {
            node->right = addNode(node->right, value);
        } else {
            node->count++;
        }

        return node;
    }

    int depthTree(Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = depthTree(node->left);
        int rightDepth = depthTree(node->right);

        return 1 + std::max(leftDepth, rightDepth);
    }

    int searchTree(Node *node, const T &value) const {
        if (node == nullptr) {
            return 0;
        }

        if (value < node->value) {
            return searchTree(node->left, value);
        } else if (value > node->value) {
            return searchTree(node->right, value);
        } else {
            return node->count;
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void add(const T &value) {
        root = addNode(root, value);
    }

    int depth() const {
        return depthTree(root);
    }

    int search(const T &value) const {
        return searchTree(root, value);
    }
};


#endif  // INCLUDE_BST_H_