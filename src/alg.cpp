// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>TREE;
  char dist = 'a' - 'A';
    std::string word;
    std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return TREE;
  }
  while (!file.eof()) {
    char symbol = file.get();
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
      if (symbol >= 'A' && symbol <= 'Z')
        symbol += dist;
      word += symbol;
    } else if (word != "") {
      TREE.add(word);
      word = "";
    }
  }
  file.close();
  return TREE;
}
