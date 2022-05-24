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
  std::string simbol = "";
  if (!file) {
    throw std::string("Error! ");
}
while (!file.eof()) {
  simbol = "";
  while (true) {
    char a = file.get();
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
    simbol += tolower(a);
    } else {
      break;
  }
}
tree.add(simbol);
}
return tree;
}
