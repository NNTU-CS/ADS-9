// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string s = "";
  while (!file.eof()) {
    s = "";
    while (true) {
      char d = file.get();
      if ((d >= 97 && d <= 122) || (d >= 65 && d <= 90)) {
        s += tolower(d);
      } else {
        break;
      }
    }
    bst.AddNode(s);
  }
  return bst;
}
