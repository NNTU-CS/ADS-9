// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include "bst.h"

#include <iostream>
#include <string>

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int count;

        Node(const T& value) : data(value), left(nullptr), right(nullptr), count(1) {}
    };

    Node* root;

    void insert(Node*& node, const T& value) {
        if (!node) {
            node = new Node(value);
            return;
        }

        if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        } else {
            node->count++;
        }
    }

    void inorder(Node* node, std::ostream& os) const {
        if (!node) return;

        inorder(node->left, os);
        os << node->data << " (" << node->count << ")" << std::endl;
        inorder(node->right, os);
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        insert(root, value);
    }

    void inorder(std::ostream& os = std::cout) const {
        inorder(root, os);
    }
};

#endif  // INCLUDE_BST_H_
