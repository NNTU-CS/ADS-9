// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;

    Node* addNode(Node* node, const T& value) {
        if (node == nullptr) {
            node = new Node;
            node->value = value;
            node->count = 1;
            node->left = node->right = nullptr;
        } else if (node->value > value) {
            node->left = addNode(node->left, value);
        } else if (node->value < value) {
            node->right = addNode(node->right, value);
        } else {
            node->count++;
        }
        return node;
    }

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    Node* findNode(Node* node, const T& value) {
        if (node == nullptr || node->value == value) return node;
        if (value < node->value) return findNode(node->left, value);
        return findNode(node->right, value);
    }

 public:
    BST() : root(nullptr) {}
    void insert(const T& value) { root = addNode(root, value); }
    int getDepth() { return getHeight(root) - 1; }
    int count(const T& value) {
        Node* current = findNode(root, value);
        if (current == nullptr) {
            return 0;
        } else {
            return current->count;
        }
    }
};
#endif  // INCLUDE_BST_H_
