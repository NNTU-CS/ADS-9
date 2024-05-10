// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  BST<std::string> bst;
  int flag = 0;
  char ch;
  std::string word;
  while (!file.eof()) {
    ch = file.get();
    if (ch >= 'A' && ch <= 'Z') {
      ch = ch + ('a' - 'A');
    }
    if (ch >= 'a' && ch <= 'z' && flag == 0) {
      flag = 1;
      word = ch;
    } else if (ch >= 'a' && ch <= 'z' && flag == 1) {
      word += ch;
    } else {
      flag = 0;
      bst.add(word);
      word = "";
    }
  }
  file.close();
  return bst;
}
