// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> bst;
  std::string word = "";
  char lowercase = 'a' - 'A';
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::string("Error! Can not open file!");
  }
  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (ch >= 'A' && ch <= 'Z')
        ch += lowercase;
      word += ch;
    } else if (word != "") {
      bst.add(word);
      word = "";
    }
  }
  file.close();
  return bst;
}
