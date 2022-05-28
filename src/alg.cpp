// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> statistic_tree;
  while (!file.eof()) {
    std::string word;
    bool flag = true;
    while (flag) {
      char sym;
      sym = tolower(file.get());
      if (sym >= 'a' && sym <= 'z')
        word += sym;
      else
        flag = false;
    }
    statistic_tree.add(word);
  }
  return statistic_tree;
}
