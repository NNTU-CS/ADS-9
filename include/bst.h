// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template<typename T>
class BST {
 public:
    BST() : root_(nullptr) {}
    void AddValue(const T& value) {
        root_ = addNode(root_, value);
    }
    int search(const T& value) {
        return searchNode(root_, value);
    }
    int depth() {
        return getDepth(root_) - 1;
    }

 private:
    struct Node {
        Node() : count_(0), left_(nullptr), right_(nullptr) {}
        T value_;
        int count_;
        Node* left_;
        Node* right_;
    };
    Node* root_;

    Node* addNode(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value_ = value;
            root->left_ = nullptr;
            root->right_ = nullptr;
            root->count_ = 1;
        } else if (root->value_ > value) {
            root->right_ = addNode(root->right_, value);
        } else if (root->value_ < value) {
            root->left_ = addNode(root->left_, value);
        } else {
            root->count_++;
        }
        return root;
    }

    int searchNode(Node* root, const T& value) {
        if (root == nullptr) {
            return 0;
        } else if (root->value_ < value) {
            return searchNode(root->left_, value);
        } else if (root->value_ > value) {
            return searchNode(root->right_, value);
        } else if (root->value_ == value) {
            return root->count_;
        }
        return 0;
    }

    int getDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int rightTree = getDepth(root->right_);
        int leftTree = getDepth(root->left_);
        if (rightTree > leftTree) {
            return rightTree + 1;
        } else {
            return leftTree + 1;
        }
    }
};

#endif  // INCLUDE_BST_H_
