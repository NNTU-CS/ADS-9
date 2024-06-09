// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node *right;
        Node *left;
    };

    Node *root;
    Node *addNewNode(Node *, T);
    void printTree(Node *);
    int searchTree(Node *, T);
    int depthTree(Node *);
    void deleteTree(Node *);
    Node *deleteNode(Node *, T);

 public:
    BST();
    ~BST();
    void add(T);
    void print();
    int search(T);
    int depth();
    void remove(T);
};

template<typename T>
BST<T>::BST() {
    root = nullptr;
}

template<typename T>
BST<T>::~BST() {
    if (root) {
        deleteTree(root);
    }
}

template<typename T>
void BST<T>::add(T value) {
    root = addNewNode(root, value);
}

template<typename T>
typename BST<T>::Node *BST<T>::addNewNode(Node *root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value < value) {
        root->right = addNewNode(root->right, value);
    } else if (root->value > value) {
        root->left = addNewNode(root->left, value);
    } else {
        root->count += 1;
    }
    return root;
}

template<typename T>
void BST<T>::print() {
    printTree(root);
}

template<typename T>
void BST<T>::printTree(Node *root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    for (int i = 0; i < root->count; i++) {
        std::cout << root->value;
    }
    printTree(root->right);
}

template<typename T>
int BST<T>::search(T value) {
    return searchTree(root, value);
}

template<typename T>
int BST<T>::searchTree(Node *root, T value) {
    if (root == nullptr) {
        return 0;
    } else if (value > root->value) {
        return searchTree(root->right, value);  
    } else if (value < root->value) {
        return searchTree(root->left, value);
    } else {
        return root->count;
    }
}

template<typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template<typename T>
int BST<T>::depthTree(Node *root) {
    if (root == nullptr) {
        return 0
    }
    int hR = depthTree(root->right);
    int hL = depthTree(root->left);
    if (hL < hR) {
        return hR + 1;
    } else {
        return hL + 1;
    }
}

template<typename T>
void BST<T>::deleteTree(Node *root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->right);
    deleteTree(root->left);
    delete root;
    root = nullptr;
}
#endif  // INCLUDE_BST_H_
