// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
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
    int depthTree(Node*) const;
    int searchTree(Node*, const T&) const;
 public:
    BST(): root(nullptr) {}
    void add(T);
    int depth() const;
    int search(const T&) const;
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
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
    if (node->value == value) {
        return node->count;
    }
    if (node->value < value) {
        return searchTree(node->right, value);
    }
    return searchTree(node->left, value);
}

template <typename T>
int BST<T>::search(const T& value) const {
    return searchTree(root, value);
}

#endif  // INCLUDE_BST_H_
