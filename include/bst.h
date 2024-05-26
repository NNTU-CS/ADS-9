// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
template <typename T>
class BST {
 public:
    struct Node {
        T znach;
        int counter;
        Node* right;
        Node* left;
    };
 private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
 public:
    BST();
    void add(T);
    int depth();
    int search(T);
};
template <typename T>
BST <T>::BST() : root(nullptr) {}
template <typename T>
typename BST <T>::Node* BST <T>::addNode(Node* root, T znach) {
    if (root == nullptr) {
        root = new Node;
        root->znach = znach;
        root->counter = 1;
        root->left = root->right = nullptr;
    } else if (root->znach > znach) {
        root->left = addNode(root->left, znach);
    } else if (root->znach < znach) {
        root->right = addNode(root->right, znach);
    } else {
        root->counter++;
    }
    return root;
}
template <typename T>
void BST <T>::add(T znach) {
    root = addNode(root, znach);
}
template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(root->left);
        int rightDepth = depthTree(root->right);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}
template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}
BST<std::string> makeTree(const char* filename);
template <typename T>
int BST<T>::searchNode(Node* root, T znachenie) {
    if (root == nullptr)
        return 0;
    else if (root->znach == znachenie)
        return root->counter;
    else if (root->znach > znachenie)
        return searchNode(root->left, znachenie);
    else
        return searchNode(root->right, znachenie);
}
template <typename T>
int BST<T>::search(T z) {
    return searchNode(root, z);
}

#endif  // INCLUDE_BST_H_
