// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>
#include <memory>

template<typename T>
class bst {
private:
    struct Node {
        T key;
        int count;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node> &node, const T &key) {
        if (node->key == key) {
            node->count++;
        } else if (node->key > key) {
            if (!node->left) {
                node->left = std::make_unique<Node>(key);
            } else {
                insert(node->left, key);
            }
        } else {
            if (!node->right) {
                node->right = std::make_unique<Node>(key);
            } else {
                insert(node->right, key);
            }
        }
    }

    int search(const std::unique_ptr<Node> &node, const T &key) {
        if (!node) {
            return 0;
        } else if (node->key == key) {
            return node->count;
        } else if (node->key > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    int getDepth(const std::unique_ptr<Node> &node) {
        if (!node) {
            return 0;
        } else {
            return std::max(getDepth(node->left), getDepth(node->right)) + 1;
        }
    }

public:
    bst() : root(nullptr) {}

    void insert(const T &key) {
        if (!root) {
            root = std::make_unique<Node>(key);
        } else {
            insert(root, key);
        }
    }

    int search(const T &key) {
        return search(root, key);
    }

    int depth() {
        return getDepth(root) - 1;
    }
};

#endif  // INCLUDE_BST_H_
