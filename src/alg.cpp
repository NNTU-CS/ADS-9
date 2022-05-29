// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> warPeaceTree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return warPeaceTree;
  }
  std::string tex = "";
  while (!file.eof()) {
    tex = "";
    while (true) {
      char sym = file.get();
      if ((sym >= 65 && sym <= 90) || (sym >= 97 && sym <= 122))
        tex += tolower(sym);
      else
        break;
    }
    warPeaceTree.addNode(tex);
  }
  file.close();
  return warPeaceTree;
}
