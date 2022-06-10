// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream file(filename);
  if (!file.is_open()) {
      std::cout << "File error!" << std::endl;
      return Tree;
  }
  std::string str = "";
  char ch = ' ';
  while (!file.eof()) {
      ch = file.get();
      if (ch >= 'A' && ch <= 'Z') {
          ch = ('a' - 'A') + ch;
      }
      if (ch >= 'a' && ch <= 'z') {
          str = str + ch;
      } else {
          Tree.add(str);
          str = "";
      }
  }
  file.close();
  return Tree;
}
