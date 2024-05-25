// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
    };
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (!root) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
         } else if (root->value > value) {
             root->left = addNode(root->left, value);
         } else if (root->value < value) {
             root->right = addNode(root->right, value);
         } else {
             ++root->count;
         }
         return root;
    }
    int Depth(Node* root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(Depth(root->left), Depth(root->right));
    }

 public:
    BST() :root(nullptr) {}
    BST<std::string> makeTree(const char* filename);
    int depth() {
        return Depth(root) - 1;
    }
    int search(const T& value) {
        Node* cur = root;
        while (cur && cur->value != value) {
            if (cur->value > value)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (!cur) {
            return 0;
        }
        return cur->count;
    }
    void add(T value) {
        root = addNode(root, value);
    }
};
#endif  // INCLUDE_BST_H_
