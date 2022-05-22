// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
    struct Node {
        T meaning;
        int count = 0;
        Node* left = nullptr;
        Node* right = nullptr;;
    };
    Node* root;
    Node* addN(Node* root, const T& mean) {
        if (root == nullptr) {
            root = new Node;
            root->meaning = mean;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->meaning < mean) {
            root->left = addN(root->left, mean);
        } else if (root->meaning > mean) {
            root->right = addN(root->right, mean);
        } else {
            root->count++;
        }
        return root;
    }
    int searchN(Node* root, const T& mean) {
        if (root == nullptr) {
            return 0;
        } else if (root->meaning == mean) {
            return root->count;
        } else if (root->meaning < mean) {
            return searchN(root->left, mean);
        } else {
            return searchN(root->right, mean);
        }
    }
    int depthTree(Node* root) {
        int Left = 0, Right = 0;
        if (root == nullptr) {
            return 0;
        } else {
            Left = depthTree(root->left);
            Right = depthTree(root->right);
        }
        if (Right > Left) {
            return ++Right;
        } else {
            return ++Left;
        }
    }

 public:
    BST() :root(nullptr) {}
    void add(const T& mean) {
        root = addN(root, mean);
    }
    int search(const T& mean) {
        return searchN(root, mean);
    }
    int depth() {
        return depthTree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
