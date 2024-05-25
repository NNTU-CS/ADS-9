// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    int count;

    Node(const T& data) : data(data), left(nullptr), right(nullptr), count(1) {}
};

template <typename T>
class BST {
public:
    BST() : root(nullptr) {}

    void insert(const T& data);
    void inorderTraversal() const;

private:
    Node<T>* root;

    void insert(const T& data, Node<T>*& node);
    void inorderTraversal(Node<T>* node) const;
};

template <typename T>
void BST<T>::insert(const T& data) {
    insert(data, root);
}

template <typename T>
void BST<T>::insert(const T& data, Node<T>*& node) {
    if (node == nullptr) {
        node = new Node<T>(data);
        return;
    }

    if (data < node->data) {
        insert(data, node->left);
    } else if (data > node->data) {
        insert(data, node->right);
    } else {
        node->count++;
    }
}

template <typename T>
void BST<T>::inorderTraversal() const {
    inorderTraversal(root);
}

template <typename T>
void BST<T>::inorderTraversal(Node<T>* node) const {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " : " << node->count << std::endl;
        inorderTraversal(node->right);
    }
}

#endif  // INCLUDE_BST_H_
