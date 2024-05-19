// Copyright 2021 NNTU-CS
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>* bst = new BST<std::string>();
  std::ifstream file(filename);
  int count = 0;
  std::string boofer;
  bool in_string = false;
  while (!file.eof()) {
    int ch = file.get();
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
      in_string = true;
      if (ch >= 'A' && ch <= 'Z') {
        ch = ch - 32;
      }
      boofer += ch;
    } else if (in_string) {
      bst->add(boofer);
      in_string = false;
      boofer.clear();
    }
    count++;
  }
  if (in_string) {
    bst->add(boofer);
  }
  file.close();
  return *bst;
}
