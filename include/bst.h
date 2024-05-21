// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <iostream>

template <typename T>
struct TreeNode {
    T value;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : value(val), count(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
 private:
    TreeNode<T>* root;

    void insert(TreeNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
        } else if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        } else {
            node->count++;
        }
    }

    void inorder(TreeNode<T>* node, std::ostream& out) const {
        if (node) {
            inorder(node->left, out);
            out << node->value << ": " << node->count << std::endl;
            inorder(node->right, out);
        }
    }

    void clear(TreeNode<T>* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    int getDepth(TreeNode<T>* node) const {
        if (!node) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    int search(TreeNode<T>* node, const T& value) const {
        if (node == nullptr) {
            return 0;
        }
        if (value < node->value) {
            return search(node->left, value);
        } else if (value > node->value) {
            return search(node->right, value);
        } else {
            return node->count;
        }
    }

 public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& value) { insert(root, value); }

    void print(std::ostream& out) const { inorder(root, out); }

    int depth() const { return getDepth(root) - 1; }

    int search(const T& value) const { return search(root, value); }
};

#endif  // INCLUDE_BST_H_
