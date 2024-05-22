// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>

template <typename T>
class BSTNode {
public:
    T data;
    int count;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(const T& data) : data(data), count(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
public:
    BSTNode<T>* root;

    BST() : root(nullptr) {}

    void insert(const T& data) { insert(root, data); }
    void print() { print(root); }
    int count(const T& data) { return count(root, data); }

private:
    void insert(BSTNode<T>*& node, const T& data) {
        if (node == nullptr) {
            node = new BSTNode<T>(data);
        } else if (data < node->data) {
            insert(node->left, data);
        } else if (data > node->data) {
            insert(node->right, data);
        } else {
            node->count++;
        }
    }
    void print(BSTNode<T>* node) {
        if (node != nullptr) {
            print(node->left);
            std::cout << node->data << " : " << node->count << std::endl;
            print(node->right);
        }
    }
    int count(BSTNode<T>* node, const T& data) {
        if (node == nullptr) {
            return 0;
        } else if (data < node->data) {
            return count(node->left, data);
        } else if (data > node->data) {
            return count(node->right, data);
        } else {
            return node->count;
        }
    }
};

#endif  // INCLUDE_BST_H_
