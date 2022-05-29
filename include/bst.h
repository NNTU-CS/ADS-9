// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int c = 0;
        Node* left, * right;
    };
    Node* root;

    Node* addNode(Node* root, T val) {
        if (root == nullptr) {
            root = new Node;
            root->value = val;
            root->c = 1;
            root->left = root->right = nullptr;
        } else if (val < root->value) {
            root->left = addNode(root->left, val);
        } else if (val > root->value) {
            root->right = addNode(root->right, val);
        } else {
            root->c++;
        }
        return root;
    }

    int searchNode(Node* root, const T val) {
        if (root == nullptr) {
            return 0;
        } else if (root->value == val) {
            return root->c;
        } else if (root->value > val) {
            return searchNode(root->left, val);
        } else {
            return searchNode(root->right, val);
        }
    }

    int heightTree(Node* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        int rt = heightTree(root->right);
        int lt = heightTree(root->left);
        if (lt > rt) {
            return lt + 1;
        } else {
            return rt + 1;
        }
    }

 public:
    BST() : root(nullptr) {}

    void add(T val) {
        root = addNode(root, val);
    }

    int search(T val) {
        return searchNode(root, val);
    }

    int depth() {
        return heightTree(root);
    }
};

#endif  // INCLUDE_BST_H_
