// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node *left, *right;
    };
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value) {
            root->right = addNode(root->right, value);
        } else {
            root->count += 1;
        }
        return root;
    }
    int treeDepth(Node* root) {
        if (root == nullptr) return 0;
        return std::max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
    Node* searchTree(Node* root, const T& value) {
        if (root == nullptr || root->value == value) return root;
        if (value < root->value) return searchTree(root->left, value);
        return searchTree(root->right, value);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = addNode(root, value); }
    int depth() { return treeDepth(root) - 1; }
    int search(const T& value) {
        Node* current = searchTree(root, value);
        if (current == nullptr) {
            return 0;
        } else {
            return current->count;
        }
    }
};
#endif // INCLUDE_BST_H_
