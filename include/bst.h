// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        Node(const T& data) {
            data = data;
            count = 1;
            left = nullptr;
            right = nullptr;
        }
    };
    Node* root;
    int inorderTraversalN(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(inorderTraversalN(root->left), inorderTraversalN(root->right)) + 1;
    }
    Node* addN(Node* root, const T& data) {
        if (root == nullptr) {
            root = new Node;
            root->data = data;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->data > data) {
            root->left = addN(root->left, data);
        } else if (root->data < data) {
            root->right = addN(root->right, data);
        } else {
            root->count += 1;
        }
        return root;
    }

    Node* searchT(Node* root, const T& data) {
        if (root == nullptr || root->data == data) {
            return root;
        }
        if (data < root->data) {
            return searchT(root->left, data);
        }
        return searchT(root->right, data);
    }

    void BST<T>::inorderTraversal() const {
        return inorderTraversalN(root) - 1;
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(const T& data) {
        root = insertN(root, data);
    }
    void inorderTraversal() const;
    int search(const T& value) {
        Node* curr = searchT(root, value);
        if (curr == nullptr) {
            return 0;
        }
        else {
            return curr->countt;
        }
    }
    ~BST() {
        if (root) {
            delTree(root);
        }
    }
};
#endif  // INCLUDE_BST_H_
