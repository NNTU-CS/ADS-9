// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>

template<typename T>
class Node {
 public:
    T key;
    int count;
    Node *left, *right;

    explicit Node(T k) : k(k), count(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 private:
    Node<T> *root;

    void insert(Node<T> *node, const T &k) {
        if (node->k == k) {
            node->count++;
            return;
        } else if (node->k > k) {
            if (node->left == nullptr) {
                node->left = new Node<T>(k);
                return;
            }
            insert(node->left, k);
        } else {
            if (node->right == nullptr) {
                node->right = new Node<T>(k);
                return;
            }
            insert(node->right, k);
        }
    }

    int search(Node<T> *node, const T &k) {
        if (node == nullptr) {
            return 0;
        }
        if (node->k == k) {
            return node->count;
        } else if (node->k > k) {
            return search(node->left, k);
        } else {
            return search(node->right, k);
        }
    }

    int get_depth(Node<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return std::max(get_depth(node->left), get_depth(node->right)) + 1;
    }

 public:
    BST() : root(nullptr) {}

    void insert(const T &k) {
        if (root == nullptr) {
            root = new Node<T>(k);
            return;
        }
        insert(root, k);
    }

    int search(const T &k) {
        return search(root, k);
    }

    int depth() {
        return get_depth(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
