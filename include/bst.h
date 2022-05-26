// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 public:
    struct Node {
        T value;
        Node* right = nullptr;
        Node* left = nullptr;
        int count = 0;
    };
    BST() :root(nullptr) {}
    int search(T value) {
        return searchNode(root, value);
    }
    int depth() {
        return height(root)-1;
    }
    void add(T value) {
        root = addNode(root, value);
    }

 private:
    Node* root;
    Node* addNode(Node* root, T value) {
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
            root->count++;
        }
        return root;
    }
    int searchNode(Node* root, T value) {
        if (root == nullptr) {
            return 0;
        } else if (value < root->value) {
            return searchNode(root->left, value);
        } else if (value > root->value) {
            return searchNode(root->right, value);
        } else {
            return root->count;
        }
    }
    int height(Node* root) {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left > right)
            return 1 + left;
        else
            return 1 + right;
    }
};
#endif  // INCLUDE_BST_H_
