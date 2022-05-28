// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> textTree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File not found" << std::endl;
    return textTree;
  }
  std::string text = "";
  while (!file.eof()) {
    text = "";
    while (true) {
      char symb = file.get();
      if ((symb >= 65 && symb <= 90) || (symb >= 97 && symb <= 122))
        text += tolower(symb);
      else
        break;
    }
    textTree.addNode(text);
  }
  file.close();
  return textTree;
}

// Made by AndySter
