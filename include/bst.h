// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
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

    Node* addNode(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (node->data > value) {
            node->left = addNode(node->left, value);
        }
        else if (node->data < value) {
            node->right = addNode(node->right, value);
        }
        else {
            node->count++;
        }
        return node;
    }

    int depthTree(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int left_depth = depthTree(node->left);
        int right_depth = depthTree(node->right);
        return 1 + std::max(left_depth, right_depth);
    }

    int searchTree(Node* node, const T& value) const {
        if (node == nullptr) {
            return 0;
        } else if (node->data == value) {
            return node->count;
        } else if (node->data < value) {
            return searchTree(node->right, value);
        }
        return searchTree(node->left, value);
    }

public:
    BST() : root(nullptr) {}

    void add(const T& value) {
        root = addNode(root, value);
    }

    int depth() const {
        return depthTree(root) - 1;
    }

    int search(const T& value) const {
        return searchTree(root, value);
    }
};

#endif  // INCLUDE_BST_H_
