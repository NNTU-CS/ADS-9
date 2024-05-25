// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
private:
    struct Node {
        T value;
        int cnt;
        Node* left, * right;
    };
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->cnt = 1;
            root->left = root->right = nullptr;
        }
        else if (root->value > value) {
            root->left = addNode(root->left, value);
        }
        else if (root->value < value) {
            root->right = addNode(root->right, value);
        }
        else {
            root->cnt += 1;
        }
        return root;
    }
    int depthTree(Node* root) {
        if (root == nullptr)
            return 0;
        return std::max(depthTree(root->left), depthTree(root->right)) + 1;
    }
    Node* searchTree(Node* root, const T& value) {
        if (root == nullptr || root->value == value)
            return root;
        if (value < root->value)
            return searchTree(root->left, value);
        return searchTree(root->right, value);
    }

public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = addNode(root, value); }
    int depth() { return depthTree(root) - 1; }
    int search(const T& value) {
        Node* curr = searchTree(root, value);
        if (curr == nullptr) {
            return 0;
        }
        else {
            return curr->cnt;
        }
    }
};
#endif  // INCLUDE_BST_H_
