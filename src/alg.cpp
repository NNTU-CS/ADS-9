// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream file(filename);
  char ch;
  std::string wrd = "";
    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return Tree;
    }
    while (!file.eof()) {
      ch = file.get();
      if ((ch >= 'A') && (ch <= 'Z')) ch += 32;
      if ((ch >= 'a') && (ch <= 'z')) {
        wrd += ch;
      } else {
        Tree.Add(wrd);
        wrd = "";
      }
    }
    file.close();
  return Tree;
}
