// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTtree;
  std::ifstream file(filename);
  std::string res;
  while (!file.eof()) {
    char s = file.get();
    if (s >= 'A' && s <= 'Z')
        s = s + ('a' - 'A');
    if (s >= 'a' && s <= 'z') {
      res += s;
    } else {
      BSTtree.add(res);
      res.clear();
    }
  }
  return BSTtree;
}
