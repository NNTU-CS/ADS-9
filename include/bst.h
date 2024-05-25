// Copyright 2021 NNTU-CS
#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>

template<typename T>
struct TreeNode {
    T key;
    int frequency;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& k) : key(k), frequency(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
public:
    BST() : root(nullptr) {}

    void insert(const T& key);
    void inOrderPrint() const;

private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* node, const T& key);
    void inOrderPrint(TreeNode<T>* node) const;
};

template<typename T>
void BST<T>::insert(const T& key) {
    root = insert(root, key);
}

template<typename T>
TreeNode<T>* BST<T>::insert(TreeNode<T>* node, const T& key) {
    if (node == nullptr) {
        return new TreeNode<T>(key);
    }
    if (key == node->key) {
        node->frequency++;
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

template<typename T>
void BST<T>::inOrderPrint() const {
    inOrderPrint(root);
}

template<typename T>
void BST<T>::inOrderPrint(TreeNode<T>* node) const {
    if (node != nullptr) {
        inOrderPrint(node->left);
        std::cout << node->key << ": " << node->frequency << std::endl;
        inOrderPrint(node->right);
    }
}

#endif // BST_H

