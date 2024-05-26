// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>  // Для std::max

template<typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node *left;
        Node *right;

        explicit Node(const T &value) : data(value), count(1), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insert(Node *node, const T &value);

    int calculateDepth(Node *node) const;

    void clear(Node *node);

 public:
    BST();

    ~BST();

    void add(const T &value);

    int depth() const;

    int search(const T &value) const;
};

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::~BST() {
    clear(root);
}

template<typename T>
void BST<T>::clear(Node *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
typename BST<T>::Node *BST<T>::insert(Node *node, const T &value) {
    if (!node) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        node->count++;
    }
    return node;
}

template<typename T>
void BST<T>::add(const T &value) {
    root = insert(root, value);
}

template<typename T>
int BST<T>::calculateDepth(Node *node) const {
    if (!node) {
        return 0;
    }
    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

template<typename T>
int BST<T>::depth() const {
    return calculateDepth(root);
}

template<typename T>
int BST<T>::search(const T &value) const {
    Node *current = root;
    while (current) {
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return current->count;
        }
    }
    return 0;
}

#endif  // INCLUDE_BST_H
