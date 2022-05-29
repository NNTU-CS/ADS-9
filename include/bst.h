// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename T>
struct node {
    node<T>* right = nullptr;
    node<T>* left = nullptr;
    node<T>* prev = nullptr;
    int count = 0;
    T value = "";
};
template <typename T>
class BST {
 private:
    node<T>* root = nullptr;
    int height = 0;
    void getdepth(node<T>* tree, int index) {
        ++index;
        if (tree->left != nullptr) {
            getdepth(tree->left, index);
        }
        if (tree->right != nullptr) {
            getdepth(tree->right, index);
        }
        if (index > height) {
            height = index;
        }
    }
    void delnode(node<T>* node) {
        if (node->left != nullptr) {
            delnode(node->left);
        }
        if (node->right != nullptr) {
            delnode(node->right);
        }
        delete node;
    }

 public:
    BST() {
        root = nullptr;
        height = 0;
    }
    ~BST() {
        delnode(root);
    }
    void push(T item) {
        node<T>* current = root;
        node<T>* prev = nullptr;
        int pos = 0;
        while (true) {
            if (current == nullptr) {
                current = new node<T>;
                current->left = nullptr;
                current->right = nullptr;
                current->value = item;
                current->count = 1;
                if (prev != nullptr) {
                    current->prev = prev;
                    if (pos == 1) {
                        prev->right = current;
                    } else {
                        prev->left = current;
                    }
                    pos = 0;
                    prev = nullptr;
                }
                if (root == nullptr) {
                    root = current;
                }
                break;
            }
            if (current->value < item) {
                prev = current;
                pos = 1;
                current = current->right;
            } else if (current->value == item) {
                current->count++;
                break;
            } else {
                prev = current;
                pos = -1;
                current = current->left;
            }
        }
    }
    int search(T item) {
        node<T>* current = root;
        while (true) {
            if (current == nullptr) {
                throw std::string("EMPTY!");
            } else if (current->value < item) {
                current = current->right;
            } else if (current->value == item) {
                return current->count;
            } else {
                current = current->left;
            }
        }
    }
    int depth() {
        node<T>* current = root;
        getdepth(current, 0);
        return height - 1;
    }
};
#endif  // INCLUDE_BST_H_
