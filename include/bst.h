// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;

        explicit Node(const T& data) : data(data), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            node->count++;
        }
        return node;
    }

    void inorderTraversal(Node* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << ": " << node->count << std::endl;
            inorderTraversal(node->right);
        }
    }

 public:
    BST() : root(nullptr) {}
    void insert(const T& data) {
        root = insert(root, data);
    }
    void print() const {
        inorderTraversal(root);
    }
};
#endif  // INCLUDE_BST_H_
