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
            return curr->count;
        }
    }
    ~BST() {
        if (root) {
            delTree(root);
        }
    }

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
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addN(root->left, value);
        } else if (root->value < value) {
            root->right = addN(root->right, value);
        } else {
            root->countt += 1;
        }
        return root;
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

    void BST<T>::inorderTraversal() const {
        return inorderTraversal(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
