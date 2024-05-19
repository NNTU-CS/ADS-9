// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
#include <algorithm>
template <typename T>
class BST {
 public:
    struct Node {
        T key;
        int frequency;
        Node* left;
        Node* right;

        explicit Node(T k) : key(k), frequency(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    BST() : root(nullptr) {}

    void insert(const T& key) {
        root = insertRec(root, key);
    }

    int search(const T& key) const {
        Node* node = searchRec(root, key);
        return node ? node->frequency : 0;
    }

    void inorder() const {
        inorderRec(root);
    }

    int depth() const {
        return depthRec(root)-1;
    }

 private:
    Node* insertRec(Node* node, const T& key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key == node->key) {
            node->frequency++;
        } else if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else {
            node->right = insertRec(node->right, key);
        }

        return node;
    }

    Node* searchRec(Node* node, const T& key) const {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return searchRec(node->left, key);

        return searchRec(node->right, key);
    }

    void inorderRec(Node* node) const {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->key << " : " << node->frequency << std::endl;
            inorderRec(node->right);
        }
    }

    int depthRec(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = depthRec(node->left);
        int rightDepth = depthRec(node->right);
        return std::max(leftDepth, rightDepth)+1;
    }
};

#endif  // INCLUDE_BST_H_
