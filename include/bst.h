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
        T Val;
        int cntr;
        Node* left;
        Node* right;
    };

 private:
    Node* root;
    Node* addNode(Node* root, T Val);
    int depthTree(Node* root);
    int searchNode(Node* root, T Val);

 public:
    BST();
    void add(T Val);
    int depth();
    int search(T Val);
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T Val) {
    if (root == nullptr) {
        root = new Node;
        root->Val = Val;
        root->cntr = 1;
        root->left = root->right = nullptr;
    } else if (root->Val > Val) {
        root->left = addNode(root->left, Val);
    } else if (root->Val < Val) {
        root->right = addNode(root->right, Val);
    } else {
        root->cntr++;
    }
    return root;
}

template <typename T>
void BST<T>::add(T Val) {
    root = addNode(root, Val);
}

template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(root->left);
        int rightDepth = depthTree(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
}

template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template <typename T>
int BST<T>::searchNode(Node* root, T Val) {
    if (root == nullptr)
        return 0;
    else if (root->Val == Val)
        return root->cntr;
    else if (root->Val > Val)
        return searchNode(root->left, Val);
    else
        return searchNode(root->right, Val);
}

template <typename T>
int BST<T>::search(T Val) {
    return searchNode(root, Val);
}


#endif  // INCLUDE_BST_H_
