// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
   BST<std::string> tree;

  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return tree;
  }

  std::locale loc;
  std::string word;
  while (file >> std::ws) {
    char c;
    while (file.get(c) && std::isalpha(c, loc)) {
      word += std::tolower(c, loc);
    }
    if (!word.empty()) {
      tree.insert(word);
      word.clear();
    }
  }

  file.close();
  return tree;
}
