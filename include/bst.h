// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
template <typename T>
class BST {
public:
    struct NewNode {
        T val;
        int frequency;
        NewNode* right;
        NewNode* left;
    };
    BST();
    int depth();
    int search(T);
    void insert(T);
private:
    NewNode* root;
    int calculateDepth(NewNode*);
    int searchNode(NewNode*, T);
    NewNode* insertNode(NewNode*, T);
};

template <typename T>
BST <T>::BST() : root(nullptr) {}

template <typename T>
typename BST <T>::NewNode* BST <T>::insertNode(NewNode* root, T value) {
    if (root == nullptr) {
        root = new NewNode;
        root->val = value;
        root->frequency = 1;
        root->left = root->right = nullptr;
    } else if (root->val > value) {
        root->left = insertNode(root->left, value);
    } else if (root->val < value) {
        root->right = insertNode(root->right, value);
    } else {
        root->frequency++;
    }
    return root;
}

template <typename T>
void BST <T>::insert(T val) {
    root = insertNode(root, val);
}

template <typename T>
int BST<T>::calculateDepth(NewNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftD = calculateDepth(root->left);
        int rightD = calculateDepth(root->right);
        if (leftD > rightD) {
            return leftD + 1;
        } else {
            return rightD + 1;
        }
    }
}

template <typename T>
int BST<T>::depth() {
    return calculateDepth(root) - 1;
}

BST<std::string> makeTree(const char* filename);

template <typename T>
int BST<T>::searchNode(NewNode* root, T poisk) {
    if (root == nullptr)
        return 0;
    else if (root->val == poisk)
        return root->frequency;
    else if (root->val > poisk)
        return searchNode(root->left, poisk);
    else
        return searchNode(root->right, poisk);
}

template <typename T>
int BST<T>::search(T poisk) {
    return searchNode(root, poisk);
}

#endif // INCLUDE_BST_H_
