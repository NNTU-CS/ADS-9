// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;
  Node* addNode(Node* currentNode, T newValue);
  int searchTree(Node* currentNode, T targetValue);
  int depthTree(Node* currentNode);
 public:
  BST();
  void add(T newValue);
  int search(T targetValue);
  int depth();
};

template <typename T>
BST<T>::BST() {
  root = nullptr;
}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* currentNode, T newValue) {
  if (currentNode == nullptr) {
    currentNode = new Node;
    currentNode->value = newValue;
    currentNode->count = 1;
    currentNode->left = currentNode->right = nullptr;
  } else if (currentNode->value > newValue) {
    currentNode->left = addNode(currentNode->left, newValue);
  } else if (currentNode->value < newValue) {
    currentNode->right = addNode(currentNode->right, newValue);
  } else {
    currentNode->count++;
  }
  return currentNode;
}

template <typename T>
void BST<T>::add(T newValue) {
  root = addNode(root, newValue);
}

template <typename T>
int BST<T>::searchTree(Node* currentNode, T targetValue) {
  if (currentNode == nullptr) {
    return 0;
  } else if (targetValue < currentNode->value) {
    return searchTree(currentNode->left, targetValue);
  } else if (targetValue > currentNode->value) {
    return searchTree(currentNode->right, targetValue);
  } else {
    return currentNode->count;
  }
}

template <typename T>
int BST<T>::search(T targetValue) {
  return searchTree(root, targetValue);
}

template <typename T>
int BST<T>::depthTree(Node* root) {
  if (root == nullptr)
    return 0;
  int leftDepth = depthTree(root->left);
  int rightDepth = depthTree(root->right);
  return std::max(leftDepth, rightDepth) + 1;
}

template <typename T>
int BST<T>::depth() {
  return depthTree(root);
}

#endif  // INCLUDE_BST_H_
