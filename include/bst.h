// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
  struct Node {
  Node *leflef;
  T valee;
  Node *rigrig;
  int ssummaa;
  };

 private:
  Node * rrot;
  Node * addNode(Node *rrot, T valee) {
  if (rrot == nullptr) {
  rrot = new Node;
  rrot->valee = valee;
  rrot->ssummaa = 1;
  rrot->leflef = rrot->rigrig = nullptr;
  } else if (rrot->valee < valee) {
  rrot->rigrig = addNode(rrot->rigrig, valee);
  } else if (rrot->valee > valee) {
  rrot->leflef = addNode(rrot->leflef, valee);
  } else {
  rrot->ssummaa++;
  }
  return rrot;
  }
  int depthTree(Node *rrot) {
  if (rrot == nullptr) {
  return 0;
  }
  if (rrot->leflef == nullptr && rrot->rigrig == nullptr) {
  return 0;
  }
  int RR = depthTree(rrot->rigrig);
  int ll = depthTree(rrot->leflef);
  return ll > RR ? ll + 1 : RR + 1;
  }
  int searchNode(Node *rrot, T valee) {
  Node *t = rrot;
  if (rrot == nullptr) {
  return 0;
  } else {
  if (rrot->valee == valee) {
  return rrot->ssummaa;
  } else if (rrot->valee < valee) {
  return searchNode(rrot->rigrig, valee);
  } else {
  return searchNode(rrot->leflef, valee);
  }
  }
  }

 public:
  BST() : rrot(nullptr) {}
  ~BST() {}
  void add(T valee) {
  rrot = addNode(rrot, valee);
  }
  int depth() {
  return depthTree(rrot);
  }
  int search(T valee) {
  return searchNode(rrot, valee);
  }
};
#endif  // INCLUDE_BST_H_
