// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* right;
        Node* left;
    };

 private:
    Node* root;
    Node* addNode(Node* root, T value);
    int searchTree(Node* root, T value);
    int depthTree(Node* root);

 public:
    BST();
    void add(T value);
    int search(T value);
    int depth();
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = nullptr;
        root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}

template <typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}

template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth;
        leftDepth = depthTree(root->left);
        int rightDepth;
        rightDepth = depthTree(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
}

template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template <typename T>
int BST<T>::searchTree(Node* root, T value) {
    if (root == nullptr)
        return 0;
    else if (root->value == value)
        return root->count;
    else if (root->value > value)
        return searchTree(root->left, value);
    else
        return searchTree(root->right, value);
}

template <typename T>
int BST<T>::search(T value) {
    return searchTree(root, value);
}

#endif  // INCLUDE_BST_H_
