// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word = "";
  char ch;

  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
  }

  while (!file.eof()) {
    file.get(ch);
    if (isalpha(ch)) {
      ch = tolower(ch);
      word += ch;
    } else if (!(word.empty())) {
      tree.add(word);
      word = "";
    }
  }
  if (!(word.empty()))
    tree.add(word);
  file.close();
  return tree;
}
