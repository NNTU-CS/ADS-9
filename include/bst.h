// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>

template<typename T>
class BSTNode {
public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    int counter;

    BSTNode(const T& value) : data(value), counter(0), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
private:
    BSTNode<T>* root;

    void insertHelper(BSTNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new BSTNode<T>(value,1);
        } else if (value < node->data) {
                insertHelper(node->left, value);
        } else if (value > node->data) {
                insertHelper(node->right, value);
        } else {
                root->counter += 1;
        }
    }

    void inOrderTraversal(BSTNode<T>* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    int treeDepthHelper(BSTNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftDepth = treeDepthHelper(node->left);
            int rightDepth = treeDepthHelper(node->right);
            return 1 + std::max(leftDepth, rightDepth);
        }
    }

    bool searchTreeHelper(BSTNode<T>* node, const T& value) {
        if (node == nullptr) {
            return false;
        } else if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return searchTreeHelper(node->left, value);
        } else {
            return searchTreeHelper(node->right, value);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        insertHelper(root, value);
    }

    void inOrder() {
        inOrderTraversal(root);
    }

    void addNode(const T& value) {
        insert(value);
    }

    int depth() {
        return treeDepthHelper(root)-1;
    }

    bool search(const T& value) {
        BSTNode* Node = searchTreeHelper(root, value);
        if (Node == nullptr) {
            return 0;
        } else {
            return Node->counter;
        }
    }
};
#endif  // INCLUDE_BST_H_
