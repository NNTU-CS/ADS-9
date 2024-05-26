// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;
  Node* addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root.value = value;
      root.count = 1;
      root.left = root.right = nullptr
    } else if (root.value > value) {
      root.left = addNode(root.left, value);
    } else if (root.value < value) {
        root.right = addNode(root.right, value);
    } else {
      root.count++;
    }
    return root;
  }
  void printTree(Node* root) {
    if (root == nullptr)
      return;
    if (root && root->value) {
      printTree(root->left);
      for (int i = 0; i < root->count; i++) {
        std::cout << root->value << " ";
      }
      printTree(root->right);
    }
  }
  int depthTree(Node* root) {
    if (root == nullptr)
      return 0;
    int dL = depthTree(root->left);
    int dR = depthTree(root->right);
    if (dL > dR)
      return dL + 1;
    else
      return dR + 1;
  }
  int searchTree(Node* root) {
    if (root == nullptr)
      return 0;
    else if (value < root->value)
      return searchTree(root->left, value);
    else if (value > root->value)
      return searchTree(root->right, value);
    else
      return root->count;
  }
  void delTree(Node* root) {
    if (root == nullptr)
      return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
  }
  Node* delNode(Node* root, T value) {
    Node* p, * v;
    if (root == nullptr)
      return root;
    else if (value < root->value)
      root->left = delNode(root->left, value);
    else if (value > root->value)
      root->right = delNode(root->right, value);
    else {
      p = root;
      if (root->right == nullptr)
        root = root->left;
      else if (root->left == nullptr)
        root = root->right;
      else {
        v = root->left;
        if (v->right) {
          while (v->right->right) {
            v = v->right;
          }
          root->value = v->right->value;
          root->count = v->right->count;
          p = v->right;
          v->right = v->right->left;
        } else {
          root->value = v->value;
          root->count = v->right->count;
          p = v;
          root->left = root->left->left;
        }
      }
      delete p;
    }
    return root;
  }

 public:
  BST() { root = nullptr;}
  ~BST() {
    if (root)
      delTree(root);
  }
};
#endif  // INCLUDE_BST_H_
