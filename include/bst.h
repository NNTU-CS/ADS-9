// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
  struct X {
T value;
    int count;
X* left;
X* right;
  };
X* root;
X* addX(X*, T);
  int serchtree(X*, T);
  int depthtree(X*);
 public:
  BST();
  void add(T);
  int search(T);
  int depth();
};

template <typename T>
BST<T>::BST() {
root = nullptr;
}

template <typename T>
typename BST<T>::X* BST<T>::addX(X* root, T value) {
  if (root == nullptr) {
root = new X;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addX(root->left, value);
  } else if (root->value < value) {
    root->right = addX(root->right, value);
  } else {
    root->count++;
  }
  return root;
}

template <typename T>
void BST<T>::add(T value) {
  root = addX(root, value);
}

template <typename T>
int BST<T>::serchtree(X* root, T value) {
  if (root == nullptr) {
    return 0;
  } else if (value < root->value) {
    return serchtree(root->left, value);
  } else if (value > root->value) {
    return serchtree(root->right, value);
  } else {
    return root->count;
  }
}

template <typename T>
int BST<T>::search(T value) {
  return serchtree(root, value);
}

template <typename T>
int BST<T>::depthtree(X* root) {
  if (root == nullptr)
    return 0;
  int hleft = depthtree(root->left);
  int hright = depthtree(root->right);
  if (hleft > hright) {
    return hleft + 1;
  } else {
    return hright + 1;
  }
}

template <typename T>
int BST<T>::depth() {
  return depthtree(root) - 1;
}
#endif  // INCLUDE_BST_H_
