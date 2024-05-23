// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <iostream>
#include <string>
template <typename T>
class BST {
public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };

private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);

public:
    BST();
    void add(T);
    int search(T);
    int depth();
};
template <typename T>
BST <T>::BST() : root(nullptr) {}
template <typename T>
typename BST <T>::Node* BST <T>:: addNode(Node* root, T value) {
        if (root == nullptr) {
            root = new Node;
            root -> value = value;
            root -> count = 1;
            root -> left = root -> right = nullptr;
        }
        else if (root -> value > value) {
            root -> left = addNode(root -> left, value);
        }
        else if (root -> value < value) {
            root -> right = addNode(root -> right, value);
        }
        else
            root -> count++;
        return root;
}
template <typename T>
int BST <T>:: depthTree(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            return 1 + std::max(depthTree(root->left), depthTree(root->right));
        }
}
template <typename T>
int  BST <T>::searchNode(Node* root, T value) {
        if (root == nullptr) {
            return 0;
        }
        else if (root -> value == value) {
            return root->count;
        }
        else if (root -> value > value) {
            return searchNode(root -> left, value);
        }
        else {
            return searchNode(root -> right, value);
        }
}
template <typename T>
void BST <T>::add(T value) {
        root = addNode(root, value);
}
template <typename T>
int  BST <T>:: depth() {
        if (root) {
            return depthTree(root)-1;
        }
    return 0;
}
template <typename T>
int  BST <T>::search(T value) {
        return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
