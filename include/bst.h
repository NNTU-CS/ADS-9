// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>

template<typename T>
class Node {
 public:
    T key;
    Node *left, *right;

    explicit Node(T k): key(k), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 private:
    Node<T> *root;

    void insert(Node<T> *node, const T &key) {
        if (node->key == key) {
            return;
        } else if (node->key > key) {
            if (node->left == nullptr) {
                node->left = new Node<T>(key);
                return;
            }

            insert(node->left, key);
        } else {
            if (node->left == nullptr) {
                node->left = new Node<T>(key);
                return;
            }

            insert(node->right, key);
        }
    }
 public:
    BST(): root(nullptr) {}

    void insert(const T &key) {
        if (root == nullptr) {
            root = new Node<T>(key);
            return;
        }

        insert(root, key);
    }
};

#endif  // INCLUDE_BST_H_
