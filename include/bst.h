// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    BST();
    ~BST();
    void add(T);
    int depth();
    int search(T);
 private:
    struct Node {
        T value;
        int cnt = 0;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
    void delTree(Node*);
};

template <typename T>
BST<T>::BST(): root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    if (root) {
        delTree(root);
    }
}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T _v) {
    if (root == nullptr) {
        root = new Node;
        root->value = _v;
        root->cnt = 1;
        root->left = root->right = nullptr;
    } else if (root->value > _v) {
        root->left = addNode(root->left, _v);
    } else if (root->value < _v) {
        root->right = addNode(root->right, _v);
    } else {
        root->cnt += 1;
    }
    return root;
}

template<typename T>
void BST <T>::delTree(Node *root) {
  if (root == nullptr) {
    return;
  } else {
      delTree(root->left);
      delTree(root->right);
      delete root;
  }
}

template<typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int Right, Left;
        Right = depthTree(root->right);
        Left = depthTree(root->left);
        if (Right > Left) {
            return Right + 1;
        } else {
            return Left + 1;
        }
    }
}

template<typename T>
int BST<T>::searchNode(Node* root, T _v) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == _v) {
        return root->cnt;
    } else if (root->value > _v) {
        return searchNode(root->left, _v);
    } else {
        return searchNode(root->right, _v);
    }
}

template<typename T>
void BST<T>::add(T _v) {
    root = addNode(root, _v);
}

template<typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template<typename T>
int BST<T>::search(T _v) {
    return searchNode(root, _v);
}

#endif  // INCLUDE_BST_H_
