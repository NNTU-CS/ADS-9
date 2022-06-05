// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream fin(filename);
  if (!fin.is_open()) {
      std::cout << "File not open!" << std::endl;
      return Tree;
  }
  char str;
  std::string word = "";
  while (!fin.eof()) {
      str = fin.get();
      if (str <= 'Z' && str >= 'A') {
          str = str + ('a' - 'A');
      }
      if (str <= 'z' && str >= 'a') {
          word += str;
      } else {
          Tree.add(word);
          word = "";
      }
  }
  fin.close();
  return Tree;
}
