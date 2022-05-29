// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  char cout;
  std::string word;
  while (file.get(cout)) {
    if (('A' <= cout && cout <= 'Z') || ('a' <= cout && cout <= 'z')) {
      if ('A' <= cout && cout <= 'Z') {
        cout += 32;
      }
      word.push_back(cout);
    } else {
      tree.add(word);
      word.clear();
      continue;
    }
  }
  file.close();
  return tree;
}
