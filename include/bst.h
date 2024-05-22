// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <string>

template <typename T>
struct Node {
    T data;
    int frequency;
    Node* left;
    Node* right;
    Node(const T& data) : data(data), frequency(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
 private:
    Node<T>* root;
    Node<T>* insert(Node<T>* node, const T& data) {
        if (node == nullptr) {
            return new Node<T>(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            node->frequency++;
        }
        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node<T>* deleteNode(Node<T>* node, const T& data) {
        if (node == nullptr) {
            return node;
        }
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                node = temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                node = temp;
            } else {
                Node<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->frequency = temp->frequency;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
    void inorderTraversal(Node<T>* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << ": " << node->frequency << std::endl;
            inorderTraversal(node->right);
        }
    }

 public:
    BST() : root(nullptr) {}
    void insert(const T& data) {
        root = insert(root, data);
    }
    void deleteNode(const T& data) {
        root = deleteNode(root, data);
    }
    void printTree() {
        inorderTraversal(root);
    }
};
#endif  // INCLUDE_BST_H_
