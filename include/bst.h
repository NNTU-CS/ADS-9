// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
#include <algorithm>

template<typename MyType>
struct TreeNode {
    MyType value;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const MyType& val) {
       value = val;
       count = 1;
       left = nullptr;
       right = nullptr;
    }
};

template <typename T>
class BST {
 public:
    TreeNode<T>* mainTree;

    BST()  {
        mainTree = nullptr;
    }

    void insert(const T& value) {
        mainTree = PrivatInsert(mainTree, value);
    }

    int search(const T& value)  {
        TreeNode<T>* node = PrivatSearch(mainTree, value);
        if (node) {
            return node->count;
        } else {
            return 0;
        }
    }
    int depth()  {
        return PrivatDepth(mainTree) - 1;
    }

 private:
    TreeNode<T>* PrivatInsert(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value == node->value) {
            node->count++;
        } else if (value < node->value) {
            node->left = PrivatInsert(node->left, value);
        } else {
            node->right = PrivatInsert(node->right, value);
        }
        return node;
    }
    TreeNode<T>* PrivatSearch(TreeNode<T>* node, const T& value)  {
        if (node == nullptr || node->value == value)
            return node;

        if (value < node->value)
            return PrivatSearch(node->left, value);

        return PrivatSearch(node->right, value);
    }
    int PrivatDepth(TreeNode<T>* node)  {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = PrivatDepth(node->left);
        int rightDepth = PrivatDepth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
};
#endif  // INCLUDE_BST_H_
