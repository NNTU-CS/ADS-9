// Copyright 2021 thefreakestcopyrighter
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <class T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };

 private:
    Node* root;

    Node* addNode(Node* root, T value) {
        if (!root) {
            root = new Node{ value, 1, nullptr, nullptr };
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value) {
            root->right = addNode(root->right, value);
        } else {
            root->count++;
        }
        return root;
    }

    int depthTree(Node* root) {
        if (!root) { return 0; }
        int left = depthTree(root->left);
        int right = depthTree(root->right);
        return (left > right) ? (left + 1) : (right + 1);
    }

    Node* searchNode(Node* root, T value) {
        if (!root) {
            return root;
        } else if (root->value > value) {
            return searchNode(root->left, value);
        } else if (root->value < value) {
            return searchNode(root->right, value);
        } else {
            return root;
        }
    }

 public:
    BST() : root(nullptr) {}

    void add(T value) {
        root = addNode(root, value);
    }

    int depth() {
        return depthTree(root) - 1; // хз
    }

    int search(T value) {
        Node* node = searchNode(root, value);
        if (!node) { return 0; }
        return node->count;
    }
};

#endif  // INCLUDE_BST_H_
