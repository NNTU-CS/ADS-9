// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include<iostream>
template<typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };

    BST(): root(nullptr) {}

    void add(T value) {
        root = addNode(root, value);
    }

    int depth() {
        return depthNode(root) - 1;
    }

    int search(T value) {
        return searchNode(root, value);
    }

 private:
    Node* root;

    Node* addNode(Node* root, T value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->right = addNode(root->right, value);
        } else if (root->value < value) {
            root->left = addNode(root->left, value);
        } else {
            root->count++;
        }
        return root;
    }

    int searchNode(Node* root, T value) {
        if (root == nullptr) {
            return 0;
        }
        if (root->value > value) {
            return searchNode(root->right, value);
        }
        if (root->value < value) {
            return searchNode(root->left, value);
        }
        if (root->value == value) {
            return root->count;
        }
        return 0;
    }

    int depthNode(Node* root) {
        int left = 0;
        int right = 0;
        if (root == nullptr) {
            return 0;
        } else {
            left = depthNode(root->left);
            right = depthNode(root->right);
        }
        if (left > right) {
            return left + 1;
        }
        if (left <= right) {
            return right + 1;
        }
        return 0;
    }
};
#endif  // INCLUDE_BST_H_
