// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template<typename T>
class BST {
 public:
    BST() : root(nullptr) {}

    void AddValue(const T& value) {
        root = addNode(root, value);
    }

    int search(const T& value) {
        return searchNode(root, value);
    }

    int depth() {
        return getDepth(root) - 1;
    }

 private:
    struct BSTNode {
        BSTNode() : count(0), left(nullptr), right(nullptr) {}
        T value;
        int count;
        BSTNode* left;
        BSTNode* right;
    };

    BSTNode* root;

    BSTNode* addNode(BSTNode* root, const T& value) {
        if (root == nullptr) {
            root = new BSTNode;
            root->value = value;
            root->left = nullptr;
            root->right = nullptr;
            root->count = 1;
        } else if (root->value > value) {
            root->right = addNode(root->right, value);
        } else if (root->value < value) {
            root->left = addNode(root->left, value);
        } else {
            root->count++;
        }
        return root;
    }

    int searchNode(BSTNode* root, const T& value) {
        if (root == nullptr) {
            return 0;
        } else if (root->value < value) {
            return searchNode(root->left, value);
        } else if (root->value > value) {
            return searchNode(root->right, value);
        } else if (root->value == value) {
            return root->count;
        }
        return 0;
    }

    int getDepth(BSTNode* root) {
        if (!root) {
            return 0;
        }
        int rightTree = getDepth(root->right);
        int leftTree = getDepth(root->left);
        return std::max (rightTree, leftTree) + 1;
    }
};

#endif  // INCLUDE_BST_H_
