// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#pragma once
#include <string>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    int count;

    Node(const T& value) : data(value), left(nullptr), right(nullptr), count(1) {}
};

template <typename T>
class BST {
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, const T& value) {
        if (!node) {
            return new Node<T>(value);
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

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    int getCount(const T& value) const {
        Node<T>* node = root;
        while (node) {
            if (value < node->data) {
                node = node->left;
            } else if (value > node->data) {
                node = node->right;
            } else {
                return node->count;
            }
        }
        return 0;
    }
};
#endif  // INCLUDE_BST_H_
