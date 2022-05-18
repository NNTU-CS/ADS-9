// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T val;
    int count;
    Node * l;
    Node * r;
  };

 private:
  Node * rt;
  Node * addNode(Node *rt, T val) {
    if (rt == nullptr) {
      rt = new Node;
      rt->val = val;
      rt->count = 1;
      rt->l = rt->r = nullptr;
    } else if (rt->val > val) {
      rt->l = addNode(rt->l, val);
    } else if (rt->val < val) {
      rt->r = addNode(rt->r, val);
    } else {
      rt->count++;
    }
    return rt;
  }
  int depthTree(Node *rt) {
    if (rt == nullptr)
      return 0;
    if (rt->l == nullptr && rt->r == nullptr)
      return 0;
    int lh = depthTree(rt->l);
    int rh = depthTree(rt->r);
    return lh > rh ? lh + 1 : rh + 1;
  }
  int searchNode(Node *rt, T val) {
    Node *t = rt;
    if (rt == nullptr) {
      return 0;
    } else {
      if (rt->val == val)
        return rt->count;
      else if (rt->val < val)
        return searchNode(rt->r, val);
      else
        return searchNode(rt->l, val);
    }
  }

 public:
  BST() : rt(nullptr) {}
  ~BST() {}

  void add(T val) {
    rt = addNode(rt, val);
  }
  int depth() {
    return depthTree(rt);
  }
  int search(T val) {
    return searchNode(rt, val);
  }
};

#endif  // INCLUDE_BST_H_
