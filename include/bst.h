// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
template <typename T>
class BST {
 public:
    struct Node {
        T data;
        int freq;
        Node* left;
        Node* right;
    };
 private:
    Node* head;
    Node* insertNode(Node*, T);
    int treeDepth(Node*);
    int findNode(Node*, T);
 public:
    BST();
    void insert(T);
    int depth();
    int search(T);
};

template <typename T>
BST<T>::BST() : head(nullptr) {}

template <typename T>
typename BST<T>::Node* BST<T>::insertNode(Node* node, T value) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->freq = 1;
        node->left = node->right = nullptr;
    } else if (node->data > value) {
        node->left = insertNode(node->left, value);
    } else if (node->data < value) {
        node->right = insertNode(node->right, value);
    } else {
        node->freq++;
    }
    return node;
}

template <typename T>
void BST<T>::insert(T value) {
    head = insertNode(head, value);
}

template <typename T>
int BST<T>::treeDepth(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = treeDepth(node->left);
        int rightDepth = treeDepth(node->right);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}

template <typename T>
int BST<T>::depth() {
    return treeDepth(head) - 1;
}

BST<std::string> makeTree(const char* filename);

template <typename T>
int BST<T>::findNode(Node* node, T val) {
    if (node == nullptr)
        return 0;
    else if (node->data == val)
        return node->freq;
    else if (node->data > val)
        return findNode(node->left, val);
    else
        return findNode(node->right, val);
}

template <typename T>
int BST<T>::search(T f) {
    return findNode(head, f);
}
#endif  // INCLUDE_BST_H_

