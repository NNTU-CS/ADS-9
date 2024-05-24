// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
    struct Node {
        T key;
        int coun;
        Node* left, * right;
        explicit Node(const T& val) : key(val), coun(1),
            left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* insert(Node* node, const T& key) {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            node->coun++;
        return node;
    }
    int search(Node* node, const T& key) {
        return node ? (key < node->key ? search(node->left, key) :
            (key > node->key ? search(node->right, key)
                : node->coun)) : 0;
    }
    int depth(Node* node) {
        return node ? 1 + std::max(depth(node->left),
            depth(node->right)) : 0;
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& key) { root = insert(root, key); }
    int search(const T& key) { return search(root, key); }
    int depth() { return depth(root) - 1; }
};

#endif  // INCLUDE_BST_H_
