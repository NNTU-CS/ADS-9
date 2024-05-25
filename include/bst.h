// Copyright 2021 NNTU-CS

#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <iostream>

template<typename T>
struct TreeNode {
    T key;
    int frequency;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(const T& k) : key(k), frequency(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 public:
    BST() : root(nullptr) {}

    void insert(const T& key);
    void inOrderPrint() const;
    int depth() const;
    int search(const T& key) const;

 private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* node, const T& key);
    void inOrderPrint(TreeNode<T>* node) const;
    int depth(TreeNode<T>* node) const;
    TreeNode<T>* search(TreeNode<T>* node, const T& key) const;
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

template<typename T>
int BST<T>::depth() const {
    return depth(root);
}

template<typename T>
int BST<T>::depth(TreeNode<T>* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

template<typename T>
int BST<T>::search(const T& key) const {
    TreeNode<T>* result = search(root, key);
    return result ? result->frequency : 0;
}

template<typename T>
TreeNode<T>* BST<T>::search(TreeNode<T>* node, const T& key) const {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

#endif  // INCLUDE_BST_H_
