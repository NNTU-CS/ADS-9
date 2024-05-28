// Copyright 2021 NNTU-CS
#include  <iostream>                                                                                                         #include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> TREE;
  std::ifstream file(filename);
  std::string w;
  while (!file.eof()) {
    int ch = file.get();
    if (ch >= 'A' && ch <= 'Z') {
      ch += 32;
      w += ch;
    } else if (ch >= 'a' && ch <= 'z') {
      w += ch;
    } else {
      TREE.addNode(w);
      w = "";
    }
  }
  file.close();
  return TREE;
}
