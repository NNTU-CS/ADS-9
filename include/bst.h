// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename T>
class BST {
 public:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        Node(T val) : data(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const T& value) {
        root = insertRec(root, value);
    }

 private:
    Node* insertRec(Node* node, const T& value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else {
            node->count++;
        }
        return node;
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

#endif  // INCLUDE_BST_H_
