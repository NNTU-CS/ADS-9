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

    explicit Node(T k): key(k), count(1), left(nullptr), right(nullptr) {}
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

    int search(Node<T> *node, const T &key) {
        if (node == nullptr) {
            return 0;
        }

        if (node->key == key) {
            return node->count;
        } else if (node->key > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    int get_depth(Node<T> *node) {
        if (node == nullptr) {
            return 0;
        }

        return std::max(get_depth(node->left), get_depth(node->right)) + 1;
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

    int search(const T &key) {
        return search(root, key);
    }

    int depth() {
        return get_depth(root) - 1;
    }
};

#endif  // INCLUDE_BST_H_
