// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int count;
    };

 private:
    Node* root;
    Node* addNode(Node* root, T val) {
        if (root == nullptr) {
            root = new Node;
            root->count = 1;
            root->value = val;
            root->left = nullptr;
            root->right = nullptr;
        } else {
            if (val > root->value) root->right = addNode(root->right, val);
            else if (val < root->value) root->left = addNode(root->left, val);
            else
                root->count++;
        }
        return root;
    }
    int searchNode(Node* root, T val) {
        if (root == nullptr) {
            return 0;
        } else if (root->value == val) {
            return root->count;
        } else if (root->value < val) {
            return searchNode(root->right, val);
        } else {
            return searchNode(root->left, val);
        }
    }
    int heightTree(Node* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int left = heightTree(root->left);
            int right = heightTree(root->right);
            if (right > left) {
                return ++right;
            } else {
                return ++left;
            }
        }
    }

 public:
    BST() {
        root = nullptr;
    }
    void addNode_(T val) {
        root = addNode(root, val);
    }
    int depth() {
        return heightTree(root) - 1;
    }
    int search(T val) {
        return searchNode(root, val);
    }
};
#endif  // INCLUDE_BST_H_
