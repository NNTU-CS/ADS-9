// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  std::string word;
  char s;
  BST<std::string> three;
  while (file.get(s)) {
    if (isalpha(s)) {
      word += tolower(s);
    }
    else {
      three.addNew(word);
      word.clear();
    }
  }
  file.close();
  return three;
}
