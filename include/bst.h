// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int set;
    Node* r;
    Node* l;
  };
BST(): top(nullptr) {}
~BST() {}
void add(T value) {
  top = addNode(top, value);
}
int depth() {
  return depthTree(top);
}
int search(T value) {
  return searchNode(top, value);
}

 private:
  Node* top;
  Node* addNode(Node* top, T value) {
    if (top == nullptr) {
      top = new Node;
      top->value = value;
      top->set = 1;
      top->l = top->r = nullptr;
    } else if (top->value > value) {
      top->l = addNode(top->l, value);
    } else if (top->value < value) {
      top->r = addNode(top->r, value);
    } else {
      top->set++;
    }
    return top;
  }
  int depthTree(Node* top) {
    if (top == nullptr)
      return 0;
    if ((top->l == nullptr) && (top->r == nullptr)) {
      return 0;
    }
    int L = depthTree(top->l);
    int R = depthTree(top->r);
    return (L > R ? L : R) + 1;
  }
  int searchNode(Node* top, T value) {
    if (top == nullptr)
      return 0;
    else if (top->value > value)
      return searchNode(top->l, value);
    else if (top->value < value)
      return searchNode(top->r, value);
    else
      return top->set;
  }
};
#endif  // INCLUDE_BST_H_
