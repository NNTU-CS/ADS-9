// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>
template<typename T>
struct Node {
    T key;
    int count;
    Node* left, * right;

    explicit Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 private:
    Node<T>* root;

    int height(Node<T>* node) {
        return node ? 1 + std::max(height(node->left), height(node->right)) : 0;
    }

    Node<T>* add(Node<T>* node, T key) {
        if (!node) {
            return new Node<T>(key);
        }
        if (key < node->key) {
            node->left = add(node->left, key);
        } else if (key > node->key) {
            node->right = add(node->right, key);
        } else {
            node->count++;
        }
        return node;
    }


    int findValue(Node<T>* node, T key) const {
        if (!node) return 0;
        if (key == node->key) return node->count;
        return key < node->key ? findValue(node->left, key) : findValue(node->right, key);
    }


    void deleteTree(Node<T>* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }


 public:
    BST() : root(nullptr) {}

    void add(T key) {
        root = add(root, key);
    }

    int depth() {
        return height(root) - 1;
    }

    int search(T key) {
        return findValue(root, key);
    }

    ~BST() {
        deleteTree(root);
    }
};

#endif  // INCLUDE_BST_H_
