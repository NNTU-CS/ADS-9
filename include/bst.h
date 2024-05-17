// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template <typename T>
class BST {
private:
    struct Node {
        T val;
        int cnt;
        Node* left;
        Node* right;
        explicit Node(T v): val(v), cnt(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* addNode(Node*, const T&);
    int depthTree(Node*) const;
    int searchTree(Node*, const T&) const;

public:
    BST(): root(nullptr) {}

    void add(const T&);
    int depth() const;
    int search(const T&) const;
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* node, const T& value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (node->val > value) {
        node->left = addNode(node->left, value);
    } else if (node->val < value) {
        node->right = addNode(node->right, value);
    } else {
        node->cnt++;
    }
    return node;
}

template <typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template <typename T>
int BST<T>::depthTree(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    int leftDepth = depthTree(node->left);
    int rightDepth = depthTree(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

template <typename T>
int BST<T>::depth() const {
    return depthTree(root) - 1;
}

template <typename T>
int BST<T>::searchTree(Node* node, const T& value) const {
    if (node == nullptr) {
        return 0;
    }
    if (node->val == value) {
        return node->cnt;
    }
    if (node->val < value) {
        return searchTree(node->right, value);
    }
    return searchTree(node->left, value);
}

template <typename T>
int BST<T>::search(const T& value) const {
    return searchTree(root, value);
}

#endif  // INCLUDE_BST_H_