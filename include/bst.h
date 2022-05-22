// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    BST() :root(nullptr) {}
    ~BST() {}
    void add(T data) {
        root = addNode(root, data);
    }
    int depth() {
        return depthTree(root);
    }
    int search(T data) {
        return searchNode(root, data);
    }

 private:
    Node* root;
    Node* addNode(Node* root, T data) {
        if (root == nullptr) {
            root = new Node;
            root->value = data;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value < data) {
            root->right = addNode(root->right, data);
        } else if (root->value > data) {
            root->left = addNode(root->left, data);
        } else {
            root->count++;
        }
        return root;
    }
    int depthTree(Node* root) {
        int depth_left, depth_right;
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        depth_left = depthTree(root->left);
        depth_right = depthTree(root->right);
        if (depth_left > depth_right) {
            return depth_left + 1;
        } else {
            return depth_right + 1;
        }
    }
    int searchNode(Node* root, T data) {
        if (root == nullptr)
            return 0;
        else if (root->value < data)
            return searchNode(root->right, data);
        else if (root->value > data)
            return searchNode(root->left, data);
        else
            return root->count;
    }
};
#endif  // INCLUDE_BST_H_
