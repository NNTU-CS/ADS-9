// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <vector>
#include <utility>

template <typename T>
class BST {
 public:
    struct Node {
        T data;
        int frequency;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), frequency(1), left(nullptr), right(nullptr) {}
    };

    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    void inorder(std::vector<std::pair<T, int>>& result) const {
        inorder(root, result);
    }

 private:
    Node* root;
    Node* insert(Node* node, const T& value) {
        if (!node) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            node->frequency++;  // Если слово уже существует, увеличиваем его частоту
        }

        return node;
    }

    void inorder(Node* node, std::vector<std::pair<T, int>>& result) const {
        if (node) {
            inorder(node->left, result);
            result.push_back({node->data, node->frequency});
            inorder(node->right, result);
        }
    }
};

#endif  // INCLUDE_BST_H_
