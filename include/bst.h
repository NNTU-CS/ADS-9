// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
#include <algorithm>

template<typename T>
class BST {
private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;

        Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, const T& key) {
        if (!node) {
            node = new Node(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        } else {
            node->count++;
        }
    }

    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->key << ": " << node->count << std::endl;
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    int depth(Node* node) const {
        if (!node) return 0;
        int left_depth = depth(node->left);
        int right_depth = depth(node->right);
        return std::max(left_depth, right_depth) + 1;
    }

    int search(Node* node, const T& key, int current_depth) const {
        if (!node) return -1; // Если узел не найден
        if (key < node->key) {
            return search(node->left, key, current_depth + 1);
        } else if (key > node->key) {
            return search(node->right, key, current_depth + 1);
        } else {
            return current_depth;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroy(root);
    }

    void insert(const T& key) {
        insert(root, key);
    }

    void inorder() const {
        inorder(root);
    }

    int depth() const {
        return depth(root);
    }

    int search(const T& key) const {
        return search(root, key, 0);
    }
};

#endif  // INCLUDE_BST_H_
