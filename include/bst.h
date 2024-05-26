// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename T>
class BST {
 public:
    struct Node {
        T data;
        int count;
        Node* right;
        Node* left;

        explicit Node(const T& data) : data(data), count(1), right(nullptr), left(nullptr) {}
    };

 private:
    Node* root;

    Node* addNode(Node* node, const T& data);
    int depthTree(Node* node);
    int searchNode(Node* node, const T& data);

 public:
    BST() : root(nullptr) {}
    void add(const T& data);
    int depth();
    int search(const T& data);
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* node, const T& data) {
    if (node == nullptr) {
        return new Node(data);
    } else if (node->data > data) {
        node->left = addNode(node->left, data);
    } else if (node->data < data) {
        node->right = addNode(node->right, data);
    } else {
        node->count++;
    }
    return node;
}

template <typename T>
void BST<T>::add(const T& data) {
    root = addNode(root, data);
}

template <typename T>
int BST<T>::depthTree(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(node->left);
        int rightDepth = depthTree(node->right);
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

template <typename T>
int BST<T>::searchNode(Node* node, const T& data) {
    if (node == nullptr) {
        return 0;
    } else if (node->data == data) {
        return node->count;
    } else if (node->data > data) {
        return searchNode(node->left, data);
    } else {
        return searchNode(node->right, data);
    }
}

template <typename T>
int BST<T>::search(const T& data) {
    return searchNode(root, data);
}

#endif  // INCLUDE_BST_H_
