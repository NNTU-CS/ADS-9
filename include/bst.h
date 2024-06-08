// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchTree(Node*, T value);
    void delTree(Node*);

 public:
    BST();
    void add(T value);
    int depth();
    int search(T value);
    ~BST();
};
template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}
template<typename T>
void BST<T>::delTree(Node* root) {
    if (root == nullptr)
        return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
}
template<typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr)
        return 0;
    int hl = depthTree(root->left);
    int hr = depthTree(root->right);
    return (hl > hr) ? (hl + 1) : (hr + 1);
}
template<typename T>
int BST<T>::searchTree(Node* root, T value) {
    if (root == nullptr)
        return 0;
    else if (value < root->value)
        return searchTree(root->left, value);
    else if (value > root->value)
        return searchTree(root->right, value);
    else
        return root->count;
}
template<typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}
template<typename T>
int BST<T>::search(T value) {
    return searchTree(root, value);
}
template<typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}
template<typename T>
BST<T>::BST() {
    root = nullptr;
}
template<typename T>
BST<T>::~BST() {
    if (root)
        delTree(root);
}
#endif  // INCLUDE_BST_H_
