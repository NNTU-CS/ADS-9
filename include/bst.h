// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>

template <typename t>
struct node {
    node<t>* right = nullptr;
    node<t>* left = nullptr;
    node<t>* prev = nullptr;
    int count = 0;
    t value = "";
};
template <typename t>
class BST {
 private:
    node<t>* root = nullptr;
    int height = 0;
    void printtree(node<t>* tree, int index) {
        std::cout << index << " " << tree->value << std::endl;
        ++index;
        if (tree->left != nullptr) {
            printtree(tree->left, index);
        }
        if (tree->right != nullptr) {
            printtree(tree->right, index);
        }
    }
    void getdepth(node<t>* tree, int index) {
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
    void delnode(node<t>* node) {
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
    void add(t item) {
        node<t>* cur = root;
        node<t>* prev = nullptr;
        int pos = 0;
        while (true) {
            if (cur == nullptr) {
                cur = new node<t>;
                cur->left = nullptr;
                cur->right = nullptr;
                cur->value = item;
                cur->count = 1;
                if (prev != nullptr) {
                    cur->prev = prev;
                    if (pos == 1) {
                        prev->right = cur;
                    } else {
                        prev->left = cur;
                    }
                    pos = 0;
                    prev = nullptr;
                }
                if (root == nullptr) {
                    root = cur;
                }
                break;
            }
            if (cur->value < item) {
                prev = cur;
                pos = 1;
                cur = cur->right;
            } else if (cur->value == item) {
                cur->count++;
                break;
            } else {
                prev = cur;
                pos = -1;
                cur = cur->left;
            }
        }
    }
    int search(t item) {
        node<t>* cur = root;
        while (true) {
            if (cur == nullptr) {
                throw std::string("tree is empty!");
            } else if (cur->value < item) {
                cur = cur->right;
            } else if (cur->value == item) {
                return cur->count;
            } else {
                cur = cur->left;
            }
        }
    }
    void print() {
        node<t>* cur = root;
        printtree(cur, 0);
    }
    int depth() {
        node<t>* cur = root;
        getdepth(cur, 0);
        return height - 1;
    }
};
#endif  // INCLUDE_BST_H_
