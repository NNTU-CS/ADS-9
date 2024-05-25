// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
    BST() : root(nullptr) {}
    ~BST();

    void insert(const T& data);
    void inorderTraversal() const;
    int size() const;

 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        Node(const T& data) : data(data), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;
    void insert(Node*& node, const T& data);
    void inorderTraversal(Node* node) const;
    int size(Node* node) const;
};
template <typename T>
BST<T>::~BST() {
}
template <typename T>
void BST<T>::insert(const T& data) {
    insert(root, data);
}
template <typename T>
void BST<T>::insert(Node*& node, const T& data) {
    if (node == nullptr) {
        node = new Node(data);
        return;
    }
    if (data < node->data) {
        insert(node->left, data);
    } else if (data > node->data) {
        insert(node->right, data);
    } else {
        node->count++;
    }
}
template <typename T>
void BST<T>::inorderTraversal() const {
    inorderTraversal(root);
}
template <typename T>
void BST<T>::inorderTraversal(Node* node) const {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " : " << node->count << std::endl;
        inorderTraversal(node->right);
    }
}
template <typename T>
int BST<T>::size() const {
    return size(root);
}
template <typename T>
int BST<T>::size(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}
#endif  // INCLUDE_BST_H_
