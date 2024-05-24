// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
        explicit Node(const T& val) : value(val), count(1),
            left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insert(Node* node, const T& value) {
        if (!node)
            return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            node->count++;
        return node;
    }

    int search(Node* node, const T& value) {
        return node ? (value < node->value ? search(node->left, value) :
            (value > node->value ? search(node->right, value)
                : node->count)) : 0;
    }

    int depth(Node* node) {
        return node ? 1 + std::max(depth(node->left),
            depth(node->right)) : 0;
    }

    void findMostFrequent(Node* node, T& mostFrequentWord, int& maxCount) {
        if (!node)
            return;
        findMostFrequent(node->right, mostFrequentWord, maxCount);
        if (node->count > maxCount) {
            mostFrequentWord = node->value;
            maxCount = node->count;
        }
        findMostFrequent(node->left, mostFrequentWord, maxCount);
    }

    Node* remove(Node* node, const T& value) {
        if (!node)
            return nullptr;
        if (value < node->value)
            node->left = remove(node->left, value);
        else if (value > node->value)
            node->right = remove(node->right, value);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            node->value = findMin(node->right)->value;
            node->right = remove(node->right, node->value);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

 public:
    BST() : root(nullptr) {}

    void add(const T& value) { root = insert(root, value); }

    int search(const T& value) { return search(root, value); }

    int depth() { return depth(root) - 1; }

    void findMostFrequent(T& mostFrequentWord, int& maxCount) {
        mostFrequentWord = "";
        maxCount = 0;
        findMostFrequent(root, mostFrequentWord, maxCount);
    }

    void remove(const T& value) { root = remove(root, value); }
};

#endif  // INCLUDE_BST_H_
