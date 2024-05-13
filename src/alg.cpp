// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream file(filename);

  if (!file) {
    std::cerr << "Ошибка открытия файла!" << std::endl;
    return Tree;
  }
  std::string word;
  while (file >> word) {
    for (char& c : word) {
      c = std::tolower(c);
    }
    Tree.add(word);
  }

  file.close();
  return Tree;
}
