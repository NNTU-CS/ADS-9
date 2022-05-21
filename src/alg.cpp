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
  if (!file.is_open()) {
    throw std::string("Can't open file!");
  }
  while (!file.eof()) {
    s = "";
    while (true) {
      char d = file.get();
      if ((d >= 65 && d <= 90) || (d >= 97 && d <= 122)) {
        s += tolower(d);
      } else {
        break;
      }
    }
    bst.Add(s);
  }
  return bst;
}
