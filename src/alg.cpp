// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    if (root) delTree(root);
}

template <typename T>
typename BST<T>::Node* BST <T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (value < root->value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}

template <typename T>
void BST<T>::add(T value) {
    auto node = addNode(root, value);
    if (root == nullptr) {
        root = node;
    }
}

template <typename T>
void BST<T>::printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    std::cout << root->value << root->count << "_";
    printTree(root->right);
}


template <typename T>
void BST<T>::print() {
    printTree(root);
}

template <typename T>
void BST<T>::delTree(Node* root) {
    if (root == nullptr)
        return;
    else {
        delTree(root->left);
        delTree(root->right);
        delete root;
    }
}

template <typename T>
void BST<T>::clear() {
    if (root) {
        delTree(root);
        root = nullptr;
    }
}

template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int hl = depthTree(root->left);
    int hr = depthTree(root->right);
    return (hl > hr) ? (hl + 1) : (hr + 1);
}

template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template <typename T>
int BST<T>::searchNode(Node* root, T value) {
    if (root == nullptr) {
        return 0;
    }
    if (root->value == value) {
        return root->count;
    }
    if (value < root->value) {
        return searchNode(root->left, value);
    }
    if (value > root->value) {
        return searchNode(root->right, value);
    }
}

template <typename T>
int BST<T>::search(T value) {
    return searchNode(root, value);
}

template class BST<std::string>;
BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    int count = 0;
    std::string slovo;
    const char dif = 'a' - 'A';
    while (!file.eof()) {
        char ch = file.get();
        count++;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch <= 'Z') {
                ch += dif;
            }
            slovo += ch;
        } else if (!slovo.empty()) {
            tree.add(slovo);
            slovo.clear();
        }
    }
    file.close();
    return tree;
}
