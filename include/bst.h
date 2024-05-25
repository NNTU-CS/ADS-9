// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    BST(){
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
    void insert(const T& data);
    void inorderTraversal() const;
    int size() const;
    ~BST();

 private:
    Node* root;
    void insertN(Node*& node, const T& data);
    void inorderTraversalN(Node* node) const;
    int sizeN(Node* node) const;
};

BST<std::string> makeTree(const char* filename);

template <typename T>
BST<T>::~BST() {
    if (root) {
        delTree(root);
    }
}

template <typename T>
void BST<T>::insert(const T& data) {
    root = insertN(root, data);
}

template <typename T>
void BST<T>::insertN(Node*& node, const T& data) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    }
    else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else {
        root->count++;
    }
    return root;
}

template <typename T>
void BST<T>::inorderTraversal() const {
    return inorderTraversal(root) - 1;
}

template <typename T>
void BST<T>::inorderTraversalN(Node* node) const {
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
int BST<T>::sizeN(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}
#endif  // INCLUDE_BST_H_
