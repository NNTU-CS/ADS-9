// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* l;
        Node* r;
    };
 private:
    int depthTree(Node*);
    int searchNode(Node*, T);
    Node* root;
    Node* addNode(Node*, T);
 public:
    BST();
    ~BST();
    void add(T);
    int depth();
    int search(T);
};

template<typename T>
  BST<T>::BST() :root(nullptr) {}

template<typename T>
  BST<T>::~BST() {
  }

template<typename T>
  typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->l = root->r = nullptr;
    } else if (root->value < value) {
      root->r = addNode(root->r, value);
    } else if (root->value > value) {
      root->l = addNode(root->l, value);
    } else {
      root->count++;
    }
    return root;
  }

template<typename T>
  void BST<T>::add(T value) {
    root = addNode(root, value);
  }

template <typename T>
  int BST<T>::searchNode(Node* root, T value) {
    if (root == nullptr) {
      return 0;
    } else if (root->value > value) {
      return searchNode(root->l, value);
    } else if (root->value < value) {
      return searchNode(root->r, value);
    } else {
      return root->count;
    }
  }

  template<typename T>
  int BST<T>::search(T value) {
    return searchNode(root, value);
  }

template<typename T>
  int BST<T>::depthTree(Node* root) {
    if ((root == nullptr)  || (root->l == nullptr && root->r == nullptr)) {
      return 0;
    }
    int lx = depthTree(root->l);
    int rx = depthTree(root->r);
    int m = ((lx > rx) ? lx : rx) + 1;
    return m;
  }

template<typename T>
  int BST<T>::depth() {
    return depthTree(root);
  }
#endif  // INCLUDE_BST_H_
