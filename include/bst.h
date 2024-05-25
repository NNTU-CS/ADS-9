// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
public:
    BST() {
        root = nullptr;
    }
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
            return curr->cnt;
        }
    }
    ~BST();

private:
    Node* root;
    int inorderTraversalN(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(inorderTraversalN(root->left), inorderTraversalN(root->right)) + 1;
    }
    Node* addN(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->cnt = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value) {
            root->right = addNode(root->right, value);
        } else {
            root->cnt += 1;
        }
        return root;
    }
    template <typename T>
    BST<T>::~BST() {
        if (root) {
            delTree(root);
        }
    }

    Node* searchT(Node* root, const T& value) {
        if (root == nullptr || root->value == value) {
            return root;
        }
        if (value < root->value) {
            return searchT(root->left, value);
        }
        return searchT(root->right, value);
    }

    template <typename T>
    void BST<T>::inorderTraversal() const {
        return inorderTraversal(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
