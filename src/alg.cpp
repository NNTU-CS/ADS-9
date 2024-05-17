// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word;
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::string("file error!");
  }

  while (file) {
    char symbol = file.get();
    if (isalpha(symbol)) {
      symbol = tolower(symbol);
      word += symbol;
    } else if (!word.empty()) {
      tree.add(word);
      word.clear();
    }
  }
  if (!word.empty()) {
    tree.add(word);
  }

  file.close();
  return tree;
}
