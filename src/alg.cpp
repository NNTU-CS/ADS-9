// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string output;
  while (!file.eof()) {
    char chPerem = file.get();
    if (chPerem >= 65 && chPerem <=90) {
      chPerem +=32;
      output += chPerem;
      continue;
    }
    if (chPerem >=97 && chPerem <= 122) {
      output += chPerem;
    } else {
      if (!output.empty()) {
        bst.addVal(output);
      }
      output.clear();
    }
  }
  bst.addVal(output);
  file.close();
  return bst;
}
