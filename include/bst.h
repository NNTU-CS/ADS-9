// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    Node *levv;
    int ssuumma;
    Node *rht;
    T vllue;
  };

 private:
  Node * rroooot;
  Node * addNode(Node *rroooot, T vllue) {
    if (rroooot == nullptr) {
      rroooot = new Node;
      rroooot->vllue = vllue;
      rroooot->ssuumma = 1;
      rroooot->levv = rroooot->rht = nullptr;
    } else if (rroooot->vllue > vllue) {
      rroooot->levv = addNode(rroooot->levv, vllue);
    } else if (rroooot->vllue < vllue) {
      rroooot->rht = addNode(rroooot->rht, vllue);
    } else {
      rroooot->ssuumma++;
    }
    return rroooot;
  }
  int depthTree(Node *rroooot) {
    if (rroooot == nullptr) {
      return 0;
    }
    if (rroooot->levv == nullptr && rroooot->rht == nullptr) {
      return 0;
    }
    int L = depthTree(rroooot->levv);
    int R = depthTree(rroooot->rht);
    return L > R ? L + 1 : R + 1;
  }
  int searchNode(Node *rroooot, T vllue) {
    Node *t = rroooot;
    if (rroooot == nullptr) {
      return 0;
    } else {
      if (rroooot->vllue == vllue) {
        return rroooot->ssuumma;
      } else if (rroooot->vllue < vllue) {
        return searchNode(rroooot->rht, vllue);
      } else {
        return searchNode(rroooot->levv, vllue);
      }
    }
  }

 public:
  BST() : rroooot(nullptr) {}
  ~BST() {}
  void add(T vllue) {
    rroooot = addNode(rroooot, vllue);
  }
  int depth() {
    return depthTree(rroooot);
  }
  int search(T vllue) {
    return searchNode(rroooot, vllue);
  }
};
#endif  // INCLUDE_BST_H_
