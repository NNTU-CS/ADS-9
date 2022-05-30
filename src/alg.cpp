// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> der;
  std::string slova = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return der;
  }
  while (!file.eof()) {
    char symma = file.get();
    if ((symma >= 'a' && symma <= 'z') || (symma >= 'A' && symma <= 'Z')) {
      slova += tolower(symma);
    } else if (slova != "") {
      der.add(slova);
      slova = "";
    }
}
file.close();
  return der;
}
