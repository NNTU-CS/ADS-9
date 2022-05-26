// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTree;
  std::string Single_Word = "";
  std::ifstream file(filename);
  if (!file) throw std::string("File error!");
  while (!file.eof()) {
    char letter = file.get();
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
      Single_Word += tolower(letter);
    } else {
      BSTree.add(Single_Word);
      Single_Word = "";
    }
  }

  file.close();
  return BSTree;
}
