// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  char c;
  std::string word;
  while (file.get(c)) {
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
      if ('A' <= c && c <= 'Z') {
        c += 32;
      }
      word.push_back(c);
    } else {
      tree.add(word);
      word.clear();
      continue;
    }
  }
  file.close();
  return tree;
}
