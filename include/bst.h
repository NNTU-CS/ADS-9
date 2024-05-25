// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <iostream>
template <typename T>
class BST {
private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        explicit Node(T v) : data(v), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* add(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        Node* current = node;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (current->data > value) {
                current = current->left;
            } else if (current->data < value) {
                current = current->right;
            } else {
                current->count++;
                return node;
            }
        }

        if (parent->data > value) {
            parent->left = new Node(value);
        } else {
            parent->right = new Node(value);
        }

        return node;
    }

    int depthOfTree(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(depthOfTree(node->left), depthOfTree(node->right));
    }

    int WordSearch(Node* node, const T& value) const {
        while (node != nullptr) {
            if (node->data == value) {
                return node->count;
            } else if (node->data < value) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return 0;
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = add(root, value);
    }

    int depth() const {
        return depthOfTree(root) - 1;
    }

    int search(const T& value) const {
        return WordSearch(root, value);
    }
};
#endif  // INCLUDE_BST_H_
