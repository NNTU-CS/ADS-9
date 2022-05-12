// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string simb = "";
  if (!file) {
    throw std::string("Error! ");
}
while (!file.eof()) {
  simb = "";
  while (true) {
    char dop = file.get();
    if ((dop >= 65 && dop <= 90) || (dop >= 97 && dop <= 122)) {
    simb += tolower(dop); //уменьш шр
    } else {
      break;
  }
}
tree.add(simb);
}
return tree;
}
