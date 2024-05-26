// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  
  std::string someWord;
  char symbol;
  BST<std::string> tree;
  
  while (file.get(symbol)) {
    if (isalpha(symbol)) {
      someWord += tolower(symbol);
    } else {
      if (!someWord.empty()) {
        tree.add(someWord);
        someWord.clear();
      }
    }
  }
  
  if (!someWord.empty()) {
    tree.add(someWord);
  }
  
  file.close();
  return tree;
}
